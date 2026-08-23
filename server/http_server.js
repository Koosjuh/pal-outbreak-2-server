'use strict';

const http = require('http');
const fs = require('fs');
const path = require('path');
const { URL } = require('url');

const CAPTURES_DIR = path.resolve(__dirname, '..', 'captures');
const HTTP_TRACE_LOG = path.join(CAPTURES_DIR, 'http_trace.log');
try { fs.mkdirSync(CAPTURES_DIR, { recursive: true }); } catch {}
function traceHttp(line) {
  try { fs.appendFileSync(HTTP_TRACE_LOG, line + '\n'); } catch {}
}
const {
  upsertSession,
  getSession,
  markPendingOnlineFromLbs
} = require('./session_store');

const HOST_IP = '192.0.2.196';
const SNAP_PORT = 10127;
const SELF_HOST = 'stage6.sega.com';
const SNAP_HOST = 'snap01.capcom.client.sf.yav4.com';
const BASE_URL = `http://${SELF_HOST}/mhweb`;
const SNAP_HOST_PORT = `${SNAP_HOST}:${SNAP_PORT}`;
const SNAP_HEX_ADDR = HOST_IP.split('.')
  .map(octet => Number(octet).toString(16).padStart(2, '0'))
  .join('') + SNAP_PORT.toString(16).padStart(4, '0');

const ACCOUNTS_FILE = path.join(__dirname, 'accounts.json');

let accounts = {};
try {
  accounts = JSON.parse(fs.readFileSync(ACCOUNTS_FILE, 'utf8'));
} catch {
  accounts = {};
}

function saveAccounts() {
  fs.writeFileSync(ACCOUNTS_FILE, JSON.stringify(accounts, null, 2));
}

function sanitize(value, maxLen = 14) {
  return String(value || '').replace(/[^A-Za-z0-9_]/g, '').slice(0, maxLen);
}

function parseForm(body, contentType) {
  const out = {};
  if (!body.length || !String(contentType || '').includes('application/x-www-form-urlencoded')) return out;
  for (const pair of body.toString('latin1').split('&')) {
    if (!pair) continue;
    const eq = pair.indexOf('=');
    const rawKey = eq >= 0 ? pair.slice(0, eq) : pair;
    const rawValue = eq >= 0 ? pair.slice(eq + 1) : '';
    const key = decodeURIComponent(rawKey.replace(/\+/g, ' '));
    const value = decodeURIComponent(rawValue.replace(/\+/g, ' '));
    out[key] = value;
  }
  return out;
}

function csv(fields) {
  return fields.map(field => `"${String(field).replace(/"/g, '""')}"`).join(',') + ',';
}

function html(body) {
  return Buffer.from(body, 'latin1');
}

function directive(name, fields) {
  return `<html><head><!--${name}-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--<CSV>${csv(fields)}</CSV>-->
</html>`;
}

function escapeHtml(value) {
  return String(value || '')
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;');
}

function renderShell({ title, directive = '', kicker = 'ONLINE ACCESS', heading = '', active = '', footer = '', body = '' }) {
  const navLink = (href, label, id) => {
    const color = active === id ? '#ffe79a' : '#d8d8d8';
    return `<a href="${href}"><font face="Verdana, Arial" size="2" color="${color}"><b>${label}</b></font></a>`;
  };

  return `<html>
<head>
${directive ? `<!--${directive}-->` : ''}
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
<title>${escapeHtml(title)}</title>
</head>
<body bgcolor="#0b1220" text="#d8d8d8" link="#ffe79a" vlink="#ffe79a" alink="#ffffff">
<table width="100%" border="0" cellspacing="0" cellpadding="18">
  <tr>
    <td align="center">
      <table width="640" border="0" cellspacing="1" cellpadding="0" bgcolor="#65758c">
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="10" bgcolor="#16243a">
              <tr><td align="center"><font face="Verdana, Arial" size="5" color="#f3f1db"><b>RESIDENT EVIL OUTBREAK FILE #2</b></font></td></tr>
              <tr><td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>${escapeHtml(kicker)}</b></font></td></tr>
              <tr><td align="center"><font face="Verdana, Arial" size="2" color="#d8d8d8">${escapeHtml(heading)}</font></td></tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#111b2c">
              <tr><td align="center">${navLink(`${BASE_URL}/index.jsp`, 'HOME', 'home')} <font color="#65758c">|</font> ${navLink(`${BASE_URL}/create.jsp`, 'MAKE ACCOUNT', 'create')} <font color="#65758c">|</font> ${navLink(`${BASE_URL}/login.jsp`, 'LOGIN', 'login')}</td></tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="14" bgcolor="#0f1624">
              <tr><td>${body}</td></tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#182332">
              <tr><td><font face="Verdana, Arial" size="2" color="#d8d8d8"><marquee behavior="scroll" direction="left" scrollamount="2">Unofficial PAL Outbreak network online. Account creation, login and lobby handoff are active.</marquee></font></td></tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#16243a">
              <tr><td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a">${escapeHtml(footer)}</font></td></tr>
            </table>
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
</body>
</html>`;
}

function indexPage() {
  return renderShell({
    title: 'Online Access',
    heading: 'Choose an option to continue.',
    active: 'home',
    footer: 'Select account creation or login to begin.',
    body: `<table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr><td><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Main Menu</b></font></td></tr>
      <tr><td height="12"></td></tr>
      <tr><td bgcolor="#182332" style="border:1px solid #65758c; padding:10px;"><a href="${BASE_URL}/create.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>&gt; MAKE AN ACCOUNT</b></font></a></td></tr>
      <tr><td height="10"></td></tr>
      <tr><td bgcolor="#182332" style="border:1px solid #65758c; padding:10px;"><a href="${BASE_URL}/login.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>&gt; LOGIN</b></font></a></td></tr>
    </table>`
  });
}

function createForm(message = '') {
  const err = message ? `<tr><td colspan="2" bgcolor="#341118"><font face="Verdana, Arial" size="2" color="#f2c7cf"><b>${escapeHtml(message)}</b></font></td></tr><tr><td colspan="2" height="10"></td></tr>` : '';
  return renderShell({
    title: 'Create Account',
    directive: 'INP-SIGNUP',
    heading: 'Create a new account for the Outbreak network.',
    active: 'create',
    footer: 'Create a new account to get started.',
    body: `<form method="POST" action="${BASE_URL}/create.jsp">
      <table width="100%" border="0" cellspacing="0" cellpadding="6" bgcolor="#101927">
        <tr><td colspan="2"><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Account Creation</b></font></td></tr>
        <tr><td colspan="2" height="6"></td></tr>
        ${err}
        <tr><td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">User ID</font></td><td><!--INPUT-IDS--><input type="text" name="userid" maxlength="14" size="18"></td></tr>
        <tr><td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">Password</font></td><td><!--INPUT-PWS--><input type="password" name="password" maxlength="14" size="18"></td></tr>
        <tr><td colspan="2" height="8"></td></tr>
        <tr><td colspan="2"><input type="submit" value="MAKE AN ACCOUNT"></td></tr>
        <tr><td colspan="2"><a href="${BASE_URL}/index.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a">Back</font></a></td></tr>
      </table>
    </form>`
  });
}

function loginForm(message = '') {
  const err = message ? `<tr><td colspan="2" bgcolor="#341118"><font face="Verdana, Arial" size="2" color="#f2c7cf"><b>${escapeHtml(message)}</b></font></td></tr><tr><td colspan="2" height="10"></td></tr>` : '';
  return renderShell({
    title: 'Login',
    directive: 'INP-LOGIN',
    heading: 'Enter your account credentials to continue.',
    active: 'login',
    footer: 'Use your existing account to continue into the network flow.',
    body: `<form method="POST" action="${BASE_URL}/login.jsp">
      <table width="100%" border="0" cellspacing="0" cellpadding="6" bgcolor="#101927">
        <tr><td colspan="2"><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Login</b></font></td></tr>
        <tr><td colspan="2" height="6"></td></tr>
        ${err}
        <tr><td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">User ID</font></td><td><!--INPUT-ID--><input type="text" name="userid" maxlength="14" size="18"></td></tr>
        <tr><td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">Password</font></td><td><!--INPUT-PWD--><input type="password" name="password" maxlength="14" size="18"></td></tr>
        <tr><td colspan="2" height="8"></td></tr>
        <tr><td colspan="2"><input type="submit" value="LOGIN"></td></tr>
        <tr><td colspan="2"><a href="${BASE_URL}/index.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a">Back</font></a></td></tr>
      </table>
    </form>`
  });
}

function newSessid(userid, ip) {
  let sessid;
  do {
    sessid = String(Math.floor(10000000 + Math.random() * 90000000));
  } while (getSession(sessid));

  upsertSession(sessid, {
    userid,
    handle: accounts[userid]?.handle || userid,
    ip,
    loginComplete: true,
    source: 'http-protocol-minimal'
  });
  return sessid;
}
function authComplete(userid, sessid, action = 'login') {
  const startUrl = `${BASE_URL}/startsession?sessid=${sessid}`;
  const heading = action === 'create' ? 'Account created successfully.' : 'Login successful.';
  const title = action === 'create' ? 'Account Created' : 'Login Successful';
  return `<html>
<head><!--COMP-SIGNUP-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
<title>${title}</title>
</head>
<body bgcolor="#0b1220" text="#d8d8d8" link="#ffe79a" vlink="#ffe79a" alink="#ffffff">
<table width="100%" border="0" cellspacing="0" cellpadding="18">
  <tr>
    <td align="center">
      <table width="640" border="0" cellspacing="1" cellpadding="0" bgcolor="#65758c">
        <tr><td><table width="100%" border="0" cellspacing="0" cellpadding="10" bgcolor="#16243a"><tr><td align="center"><font face="Verdana, Arial" size="5" color="#f3f1db"><b>RESIDENT EVIL OUTBREAK FILE #2</b></font></td></tr><tr><td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>ONLINE ACCESS</b></font></td></tr></table></td></tr>
        <tr><td><table width="100%" border="0" cellspacing="0" cellpadding="14" bgcolor="#0f1624">
          <tr><td align="center"><font face="Verdana, Arial" size="4" color="#f3f1db"><b>${heading}</b></font></td></tr>
          <tr><td height="10"></td></tr>
          <tr><td align="center"><font face="Verdana, Arial" size="2" color="#d8d8d8">Login Name: ${escapeHtml(userid)}</font></td></tr>
          <tr><td height="10"></td></tr>
          <tr><td align="center" bgcolor="#182332"><a href="${startUrl}">Enter Lobbies</a></td></tr>
          <tr><td align="center"><!--INPUT-IDS-->${userid}\x00<br></td></tr>
        </table></td></tr>
        <tr><td><table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#16243a"><tr><td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a">Press X on Enter Lobbies to continue.</font></td></tr></table></td></tr>
      </table>
    </td>
  </tr>
</table>
</body>
</html>`;
}
function gameStart(sessid) {
  return `<html><head><!--CRS-GAME-START-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--result--><!--connection id--><!--start the game url--><!--exit game url-->
<!--<CSV>${csv(['OK', sessid, `${BASE_URL}/lbs.jsp`, `${BASE_URL}/logout.jsp`])}</CSV>-->
</html>`;
}

function lbsInfo(sessid, ip) {
  const session = getSession(sessid) || {};
  const userid = sanitize(session.userid || '', 14);
  const handle = sanitize(session.handle || userid, 12);

  if (userid) {
    markPendingOnlineFromLbs({ ip, sessid, userid, handle });
  }

  return `<html><head><!--CRS-LBS-INFO-GET-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!-- Results -->
<!-- LBS domain name + port number -->
<!-- connection number -->
<!-- Maximum number of connections -->
<!-- Additional Information 1 -->
<!-- Additional Information 2 -->
<!-- Additional Information 3 -->
<!--
<CSV>
${csv(['OK'])}
${csv([SNAP_HOST_PORT])}
${csv(['0'])}
${csv(['999'])}
${csv([`${SNAP_HEX_ADDR},PAL Lobby`])}
${csv([`<BODY>Welcome! Resident Evil Outbreak File #2 revival. Thank you for helping preserve this unique online survival horror experience.<END>`])}
${csv(['  '])}
</CSV>
-->
</html>`;
}

function handle(req, body) {
  const url = new URL(req.url, `http://${req.headers.host || SELF_HOST}`);
  const pathname = url.pathname;
  const ip = req.socket.remoteAddress;

  // 2026-05-30: capture probe for /reweb/* — the hardcoded URL
  // `http://regweb.reo.capcom.sf.yav4.com/reweb/index.jsp` lives in netwk.bin.
  // If the game fetches it during the lobby flow, the response would
  // populate the server-list work buffer at iRam0070d1c0+0x1180 (see
  // analysis/claude-press-x-root-cause-2026-05-30.md). We don't yet know
  // the response format, so for now we LOG the full request and reply
  // with an empty 200 — see what the game does with that. If we see
  // hits, we know the directory is HTTP-driven and we can RE the format.
  if (pathname.startsWith('/reweb')) {
    const ts = Date.now();
    const dumpName = `reweb_${ts}_${(req.headers.host || 'unknown').replace(/[:.]/g, '_')}_${pathname.replace(/[/]/g, '_')}`;
    try {
      const meta = {
        ts: new Date(ts).toISOString(),
        method: req.method,
        url: req.url,
        host: req.headers.host,
        userAgent: req.headers['user-agent'],
        contentType: req.headers['content-type'],
        contentLength: req.headers['content-length'],
        remote: ip,
        bodyLen: body.length,
        bodyHex: body.toString('hex'),
        bodyAscii: body.toString('latin1').replace(/[^\x20-\x7e\n\r\t]/g, '.'),
        headers: req.headers,
      };
      fs.writeFileSync(path.join(CAPTURES_DIR, `${dumpName}.json`), JSON.stringify(meta, null, 2));
      if (body.length > 0) fs.writeFileSync(path.join(CAPTURES_DIR, `${dumpName}.body.bin`), body);
      console.log(`[reweb] ★ HIT ${req.method} ${pathname} from ${ip} bodyLen=${body.length} → ${dumpName}`);
    } catch (e) {
      console.log(`[reweb] capture error: ${e.message}`);
    }
    // Return minimal empty page; will iterate after we see what arrives.
    return '<HTML><BODY></BODY></HTML>';
  }

  if (req.method === 'GET' && (pathname === '/' || pathname === '/mhweb/' || pathname === '/mhweb/index.jsp')) {
    return indexPage();
  }

  if (req.method === 'GET' && pathname === '/mhweb/create.jsp') return createForm();
  if (req.method === 'GET' && pathname === '/mhweb/login.jsp') return loginForm();

  if (req.method === 'POST' && pathname === '/mhweb/create.jsp') {
    const form = parseForm(body, req.headers['content-type']);
    const userid = sanitize(String(form.userid || '').trim(), 14);
    const password = sanitize(String(form.password || '').trim(), 14);
    if (userid.length < 3) return createForm('BAD USERID');
    if (password.length < 4) return createForm('BAD PASSWORD');
    if (accounts[userid]) return createForm('USER EXISTS');

    accounts[userid] = {
      userid,
      password,
      handle: userid,
      created: new Date().toISOString(),
      lastLogin: new Date().toISOString()
    };
    saveAccounts();

    const sessid = newSessid(userid, ip);
    console.log(`[auth] create userid=${userid} sessid=${sessid}`);
    return authComplete(userid, sessid, 'create');
  }

  if (req.method === 'POST' && pathname === '/mhweb/login.jsp') {
    const form = parseForm(body, req.headers['content-type']);
    const userid = sanitize(String(form.userid || '').trim(), 14);
    const password = sanitize(String(form.password || '').trim(), 14);
    const account = accounts[userid];
    console.log(`[auth] login userid=${userid} found=${account ? 'yes' : 'no'} match=${account && account.password === password ? 'yes' : 'no'}`);
    if (!account) return loginForm('NO USER');
    if (account.password !== password) return loginForm('BAD PASSWORD');

    account.handle = account.handle || userid;
    account.lastLogin = new Date().toISOString();
    saveAccounts();

    const sessid = newSessid(userid, ip);
    return authComplete(userid, sessid, 'login');
  }

  if (req.method === 'GET' && (pathname === '/mhweb/startsession' || pathname === '/mhweb/startsession.jsp')) {
    const sessid = sanitize(url.searchParams.get('sessid'), 20);
    if (!getSession(sessid)) return directive('CRS-ERROR', ['NG', 'BAD SESSION', `${BASE_URL}/index.jsp`]);
    return gameStart(sessid);
  }

  if (pathname === '/mhweb/lbs.jsp') {
    let sessid = sanitize(url.searchParams.get('sessid'), 20);
    if (req.method === 'POST') {
      const form = parseForm(body, req.headers['content-type']);
      sessid = sanitize(form['connection-id'] || form.sessid || sessid, 20);
    }
    if (!sessid || !getSession(sessid)) return directive('CRS-ERROR', ['NG', 'BAD LBS SESSION', `${BASE_URL}/index.jsp`]);
    console.log(`[lbs] sessid=${sessid} ip=${ip}`);
    return lbsInfo(sessid, ip);
  }

  if (pathname === '/mhweb/logout.jsp') return directive('CRS-GAME-END', ['OK', `${BASE_URL}/index.jsp`]);

  return directive('CRS-ERROR', ['NG', `UNKNOWN ${pathname}`, `${BASE_URL}/index.jsp`]);
}

const server = http.createServer((req, res) => {
  const chunks = [];
  req.on('data', chunk => chunks.push(chunk));
  req.on('end', () => {
    const body = Buffer.concat(chunks);
    console.log(`[http] ${req.method} ${req.url} from ${req.socket.remoteAddress} bytes=${body.length}`);
    const reqTs = new Date().toISOString();
    let response;
    let err = null;
    try {
      response = handle(req, body);
    } catch (e) {
      err = e;
      console.log(`[http] error ${e.stack || e.message}`);
      response = directive('CRS-ERROR', ['NG', e.message, `${BASE_URL}/index.jsp`]);
    }

    const out = html(response);
    res.writeHead(200, {
      'Content-Type': 'text/html; charset=iso-8859-1',
      'Content-Length': out.length,
      'Connection': 'close'
    });
    res.end(out);

    let directiveName = '';
    const m = String(response).match(/<!--([A-Z][A-Z0-9-]*)-->/);
    if (m) directiveName = m[1];
    traceHttp(JSON.stringify({
      ts: reqTs,
      method: req.method,
      url: req.url,
      remote: req.socket.remoteAddress,
      reqBytes: body.length,
      reqBodyPreview: body.length ? body.slice(0, 256).toString('latin1') : '',
      respDirective: directiveName,
      respBytes: out.length,
      err: err ? err.message : null,
    }));
  });
});

server.listen(80, '0.0.0.0', () => {
  console.log('HTTP protocol-minimal server listening on port 80');
  console.log(`SNAP ${SNAP_HOST_PORT} ${SNAP_HEX_ADDR}`);
});





