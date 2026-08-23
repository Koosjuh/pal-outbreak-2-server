const http = require('http');
const fs = require('fs');
const path = require('path');
const crypto = require('crypto');
const { URL } = require('url');
const {
  upsertSession,
  getSession,
  markPendingOnlineFromLbs
} = require('./session_store');

const PINE_AUTO_INJECT = true;

let pineAutoInject = async () => {};
if (PINE_AUTO_INJECT) {
  console.log('[pine] PINE_AUTO_INJECT=true; loading pine_client...');
  try {
    const { PineClient } = require(path.resolve(__dirname, '..', 'tools', 'pine_client'));
    console.log('[pine] pine_client loaded; injector armed.');

    const rawWritesEnv = process.env.PINE_WRITES;
    const writesEnv = (rawWritesEnv === undefined ? 'all' : rawWritesEnv).toLowerCase();
    const enableAll = (writesEnv === 'all');
    const enabled = new Set(writesEnv.split(',').map(s => s.trim()));

    const wantHandle     = enableAll || enabled.has('handle');
    const wantArm        = enableAll || enabled.has('arm');
    const wantState      = enableAll || enabled.has('state');
    const wantBoot       = enableAll || enabled.has('boot');
    const wantDownstream = enableAll || enabled.has('downstream');

    console.log(`[pine] PINE_WRITES=${writesEnv}  →  handle=${wantHandle} arm=${wantArm} state=${wantState} boot=${wantBoot} downstream=${wantDownstream}`);

    pineAutoInject = async (handle) => {
      if (!handle || handle.length < 1) {
        console.log('[pine] skip: empty handle');
        return;
      }

      const c = new PineClient({ port: 28011, timeoutMs: 1500 });

      try {
        await c.connect();
        const writes = [];

        if (wantHandle) {
          for (let i = 0; i < 16; i++) await c.write8(0x870870 + i, 0);
          const bytes = Buffer.from(handle.slice(0, 15), 'latin1');
          for (let i = 0; i < bytes.length; i++) await c.write8(0x870870 + i, bytes[i]);
          writes.push('handle');
        }

        if (wantArm)        { await c.write32(0x00701F30, 1);          writes.push('arm'); }
        if (wantState)      { await c.write32(0x00701F28, 0x0001A5DF); writes.push('state'); }
        if (wantBoot)       { await c.write32(0x00029F280, 1);         writes.push('boot'); }
        if (wantDownstream) { await c.write8(0x0035A279, 1);           writes.push('downstream'); }

        console.log(`[pine] INJECTED [${writes.join(',') || '(none)'}] for handle="${handle}"`);
      } catch (e) {
        console.log(`[pine] inject FAILED: ${e.message}`);
      } finally {
        try { c.close(); } catch {}
      }
    };
  } catch (e) {
    console.log(`[pine] require failed: ${e.message} — injector disabled`);
  }
} else {
  console.log('[pine] PINE_AUTO_INJECT=false; injector disabled');
}

const HOST_IP   = '192.0.2.196';
const SNAP_PORT = 10127;
const APP_HOST  = 'app01.reo.capcom.sf.yav4.com';
const SNAP_HOST = 'snap01.capcom.client.sf.yav4.com';
const SELF_HOST = 'stage6.sega.com';

const APP_HOST_PORT  = `${APP_HOST}:${SNAP_PORT}`;
const SNAP_HOST_PORT = `${SNAP_HOST}:${SNAP_PORT}`;
const SNAP_HEX_ADDR  =
  HOST_IP.split('.').map(o => parseInt(o, 10).toString(16).padStart(2, '0')).join('') +
  SNAP_PORT.toString(16).padStart(4, '0');

const BASE_URL  = `http://${SELF_HOST}/mhweb`;
const ASSET_BASE = `${BASE_URL}/assets`;

const ACTIVE_ROOT = path.resolve(__dirname, '..');
const CAPTURES_DIR = path.join(ACTIVE_ROOT, 'captures');
const ACCOUNTS_FILE = path.join(__dirname, 'accounts.json');
const WEB_ASSETS_DIR = path.join(__dirname, 'assets', 'web');
const SITE_CONTENT_FILE = path.join(__dirname, 'site_content.json');

if (!fs.existsSync(CAPTURES_DIR)) fs.mkdirSync(CAPTURES_DIR);

const TRACE_NDJSON = path.join(CAPTURES_DIR, 'protocol_trace.ndjson');

function appendTrace(entry) {
  try {
    fs.appendFileSync(TRACE_NDJSON, JSON.stringify(entry) + '\n');
  } catch (e) {
    console.log('[trace] append failed: ' + e.message);
  }
}

function nowIsoMs() {
  const d = new Date();
  return d.toISOString();
}

function sha1_8(buf) {
  return crypto.createHash('sha1').update(buf).digest('hex').slice(0, 8);
}

function toHex(buf) {
  return Buffer.isBuffer(buf) ? buf.toString('hex') : Buffer.from(buf, 'latin1').toString('hex');
}

let accounts = {};
if (fs.existsSync(ACCOUNTS_FILE)) {
  try {
    accounts = JSON.parse(fs.readFileSync(ACCOUNTS_FILE, 'utf8'));
  } catch {
    accounts = {};
  }
}

function saveAccounts() {
  fs.writeFileSync(ACCOUNTS_FILE, JSON.stringify(accounts, null, 2));
}

function loadSiteContent() {
  const defaults = {
    headline: 'Connect to the Outbreak network to manage your account and continue into the online flow.',
    ticker: [
      'Unofficial PAL Outbreak network online.',
      'Account creation and login are active.',
      'Reverse engineering is still in progress. Expect rough edges.'
    ],
    panelTitle: 'Server News & Messages',
    panelItems: [
      'Server stack: DNAS, HTTP and SN@P are all live.',
      'Sessions are issued fresh per login flow.',
      'Current focus: browser-to-game handoff.'
    ],
    footer: 'Review the latest server notes before heading online.'
  };

  try {
    if (!fs.existsSync(SITE_CONTENT_FILE)) {
      fs.writeFileSync(SITE_CONTENT_FILE, JSON.stringify(defaults, null, 2));
      return defaults;
    }

    const parsed = JSON.parse(fs.readFileSync(SITE_CONTENT_FILE, 'utf8'));

    return {
      ...defaults,
      ...parsed,
      ticker: Array.isArray(parsed.ticker) && parsed.ticker.length ? parsed.ticker : defaults.ticker,
      panelItems: Array.isArray(parsed.panelItems) && parsed.panelItems.length ? parsed.panelItems : defaults.panelItems
    };
  } catch {
    return defaults;
  }
}

function sanitize(s, maxLen = 14) {
  return (s || '').replace(/[^A-Za-z0-9_]/g, '').slice(0, maxLen);
}

function escapeHtml(s) {
  return String(s || '')
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&#39;');
}

function parseFormBody(body, contentType) {
  const out = {};
  if (!body || !body.length) return out;
  if (!(contentType || '').includes('application/x-www-form-urlencoded')) return out;

  for (const pair of body.toString('latin1').split('&')) {
    const [k, v] = pair.split('=');
    if (!k) continue;
    out[decodeURIComponent(k)] = decodeURIComponent((v || '').replace(/\+/g, ' '));
  }

  return out;
}

function directivePage(directive, csvFields, extraBody = '') {
  const csv = csvFields.map(f => `"${f}"`).join(',');

  return `<html><head><!--${directive}-->
<META HTTP-EQUIV=Content-Type CONTENT="text/html;CHARSET=iso-8859-1"></head>
<!--<CSV>${csv},</CSV>-->
${extraBody}</html>`;
}

function renderShell({ title, kicker, heading, body, footer = '', active = '', directive = '' }) {
  const site = loadSiteContent();
  const ticker = site.ticker.map(escapeHtml).join('   |   ');
  const panelRows = site.panelItems.map(item => `<tr><td><font face="Verdana, Arial" size="2" color="#d8d8d8">- ${escapeHtml(item)}</font></td></tr>`).join('');
  const activeIndex = { create: '1', login: '2', news: '3' }[active] || '0';

  const navLink = (href, label, index) => {
    const color = activeIndex === index ? '#ffe79a' : '#d8d8d8';
    return `<a href="${href}"><font face="Verdana, Arial" size="2" color="${color}"><b>${label}</b></font></a>`;
  };

  return `<html>
<head>
${directive ? `<!--${directive}-->` : ''}
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<title>${escapeHtml(title)}</title>
</head>
<body bgcolor="#0b1220" text="#d8d8d8" link="#d8d8d8" vlink="#d8d8d8" alink="#ffffff">
<table width="100%" border="0" cellspacing="0" cellpadding="18">
  <tr>
    <td align="center">
      <table width="640" border="0" cellspacing="1" cellpadding="0" bgcolor="#65758c">
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="10" bgcolor="#16243a">
              <tr>
                <td align="center"><font face="Verdana, Arial" size="5" color="#f3f1db"><b>RESIDENT EVIL OUTBREAK FILE #2</b></font></td>
              </tr>
              <tr>
                <td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>${escapeHtml(kicker)}</b></font></td>
              </tr>
              <tr>
                <td align="center"><font face="Verdana, Arial" size="2" color="#d8d8d8">${heading}</font></td>
              </tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#111b2c">
              <tr>
                <td align="center">${navLink(`${BASE_URL}/index.jsp`, 'HOME', '0')} <font color="#65758c">|</font> ${navLink(`${BASE_URL}/create.jsp`, 'MAKE ACCOUNT', '1')} <font color="#65758c">|</font> ${navLink(`${BASE_URL}/login.jsp`, 'LOGIN', '2')} <font color="#65758c">|</font> ${navLink(`${BASE_URL}/index.jsp#news`, 'NEWS', '3')}</td>
              </tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="14" bgcolor="#0f1624">
              <tr>
                <td>${body}</td>
              </tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#182332">
              <tr>
                <td><font face="Verdana, Arial" size="2" color="#d8d8d8"><marquee behavior="scroll" direction="left" scrollamount="2">${ticker}</marquee></font></td>
              </tr>
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <a name="news"></a>
            <table width="100%" border="0" cellspacing="0" cellpadding="10" bgcolor="#101927">
              <tr>
                <td><font face="Verdana, Arial" size="3" color="#f3f1db"><b>${escapeHtml(site.panelTitle)}</b></font></td>
              </tr>
              ${panelRows}
            </table>
          </td>
        </tr>
        <tr>
          <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="8" bgcolor="#16243a">
              <tr>
                <td align="center"><font face="Verdana, Arial" size="2" color="#ffe79a">${escapeHtml(footer)}</font></td>
              </tr>
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

function topPage() {
  const site = loadSiteContent();

  return renderShell({
    title: 'Outbreak Network',
    kicker: 'ONLINE ACCESS',
    heading: escapeHtml(site.headline),
    active: 'news',
    footer: escapeHtml(site.footer || 'Choose an option to begin.'),
    body: `<table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Main Menu</b></font></td>
      </tr>
      <tr>
        <td height="12"></td>
      </tr>
      <tr>
        <td bgcolor="#182332" style="border:1px solid #65758c; padding:10px;">
          <a href="${BASE_URL}/create.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>&gt; MAKE AN ACCOUNT</b></font></a>
        </td>
      </tr>
      <tr><td height="10"></td></tr>
      <tr>
        <td bgcolor="#182332" style="border:1px solid #65758c; padding:10px;">
          <a href="${BASE_URL}/login.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a"><b>&gt; LOGIN</b></font></a>
        </td>
      </tr>
      <tr><td height="18"></td></tr>
      <tr>
        <td><font face="Verdana, Arial" size="2" color="#d8d8d8">Use the plain text links if image buttons fail in the in-game browser.</font></td>
      </tr>
    </table>`
  });
}

function signupForm(errorMsg) {
  const err = errorMsg ? `<tr><td colspan="2" bgcolor="#341118"><font face="Verdana, Arial" size="2" color="#f2c7cf"><b>${escapeHtml(errorMsg)}</b></font></td></tr><tr><td colspan="2" height="10"></td></tr>` : '';

  return renderShell({
    title: 'Create Account',
    kicker: 'ONLINE ACCESS',
    heading: 'Create a new account for the Outbreak network.',
    active: 'create',
    directive: 'INP-SIGNUP',
    footer: 'Create a new account to get started.',
    body: `<form method="POST" action="${BASE_URL}/create.jsp">
      <table width="100%" border="0" cellspacing="0" cellpadding="6" bgcolor="#101927">
        <tr><td colspan="2"><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Account Creation</b></font></td></tr>
        <tr><td colspan="2" height="6"></td></tr>
        ${err}
        <tr>
          <td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">User ID</font></td>
          <td><!--INPUT-IDS--><input type="text" name="userid" maxlength="14" size="18"></td>
        </tr>
        <tr>
          <td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">Password</font></td>
          <td><!--INPUT-PWS--><input type="password" name="password" maxlength="14" size="18"></td>
        </tr>
        <tr>
          <td colspan="2"><font face="Verdana, Arial" size="1" color="#65758c">Your User ID is also your in-game handle.</font></td>
        </tr>
        <tr><td colspan="2" height="8"></td></tr>
        <tr>
          <td colspan="2">
            <input type="submit" value="MAKE AN ACCOUNT">
          </td>
        </tr>
        <tr>
          <td colspan="2"><a href="${BASE_URL}/index.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a">Back</font></a></td>
        </tr>
      </table>
    </form>`
  });
}

function loginForm(errorMsg) {
  const err = errorMsg ? `<tr><td colspan="2" bgcolor="#341118"><font face="Verdana, Arial" size="2" color="#f2c7cf"><b>${escapeHtml(errorMsg)}</b></font></td></tr><tr><td colspan="2" height="10"></td></tr>` : '';

  return renderShell({
    title: 'Login',
    kicker: 'ONLINE ACCESS',
    heading: 'Enter your account credentials to continue.',
    active: 'login',
    directive: 'INP-LOGIN',
    footer: 'Use your existing account to continue into the network flow.',
    body: `<form method="POST" action="${BASE_URL}/login.jsp">
      <table width="100%" border="0" cellspacing="0" cellpadding="6" bgcolor="#101927">
        <tr><td colspan="2"><font face="Verdana, Arial" size="3" color="#f3f1db"><b>Login</b></font></td></tr>
        <tr><td colspan="2" height="6"></td></tr>
        ${err}
        <tr>
          <td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">User ID</font></td>
          <td><!--INPUT-ID--><input type="text" name="userid" maxlength="14" size="18"></td>
        </tr>
        <tr>
          <td width="160"><font face="Verdana, Arial" size="2" color="#d8d8d8">Password</font></td>
          <td><!--INPUT-PWD--><input type="password" name="password" maxlength="14" size="18"></td>
        </tr>
        <tr><td colspan="2" height="8"></td></tr>
        <tr>
          <td colspan="2">
            <input type="submit" value="LOGIN">
          </td>
        </tr>
        <tr>
          <td colspan="2"><a href="${BASE_URL}/index.jsp"><font face="Verdana, Arial" size="2" color="#ffe79a">Back</font></a></td>
        </tr>
      </table>
    </form>`
  });
}

function sessionIdentity(sessid) {
  const session = getSession(sessid) || {};
  const userid = session.userid || '';
  const account = userid ? accounts[userid] : null;
  const handle = sanitize(session.handle || account?.handle || userid, 12);

  return {
    userid,
    handle,
    authId: handle ? `${handle}@cee-auth` : ''
  };
}

function gameStartPage(sessid) {
  const csv = [
    'OK',
    sessid,
    `${BASE_URL}/enterareas`,
    `${BASE_URL}/login`
  ].map(f => `"${f}"`).join(',');

  return `<html>
<head><!--CRS-GAME-START-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--result--><!--connection id--><!--start the game url--><!--exit game url-->
<!--<CSV>${csv},</CSV>-->
</html>`;
}

function startSessionLandingPage(sessid) {
  return `<html>
<head>
<!--CRS-GAME-START-->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<title>Login successful</title>
</head>
<body bgcolor="#0b1220" text="#d8d8d8" link="#d8d8d8" vlink="#d8d8d8" alink="#ffffff">
<br><br>
Login successful. <a href="${BASE_URL}/startsession?sessid=${escapeHtml(sessid)}">Enter lobbies</a>
<br><br>
</body>
</html>`;
}

function signupCompletePage(sessid, userid) {
  const safeUserid = escapeHtml(userid);
  const safeSessid = escapeHtml(sessid);
  const csv = [
    'OK',
    userid,
    sessid,
    `${BASE_URL}/startsession?sessid=${sessid}`,
  ].map(f => `"${f}"`).join(',');

  return `<html>
<head><!--COMP-SIGNUP-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--INPUT-IDS-->${safeUserid}
<!--INPUT-PWS-->
<!--result--><!--login_name--><!--sessid--><!--start_url-->
<!--<CSV>${csv},</CSV>-->
<br><br>
Account created. <a href="${BASE_URL}/startsession?sessid=${safeSessid}">Enter lobbies</a>
<br><br>
</html>`;
}

function enterAreasPage(sessid) {
  return enterAreasGameStartPage(sessid);
}

function enterAreasGameStartPage(sessid) {
  const csv = [
    'OK',
    sessid,
    `${BASE_URL}/lbs_info`,
    `${BASE_URL}/login`
  ].map(f => `"${f}"`).join(',');

  return `<html>
<head><!--CRS-GAME-START-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--result--><!--connection id--><!--start the game url--><!--exit game url-->
<!--<CSV>${csv},</CSV>-->
</html>`;
}

function lbsInfoPage(sessid) {
  const ident = sessionIdentity(sessid);

  const rows = [
    'OK',
    SNAP_HOST_PORT,
    '0',
    '999',
    `${SNAP_HEX_ADDR},PAL Lobby`,
    `<BODY>Welcome ${ident.handle || 'player'} to the unofficial PAL Outbreak server.<END>`,
    '  '
  ];

  return `<html>
<head>
<!--CRS-LBS-INFO-GET-->
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
${rows.map(row => `"${row}",`).join('\n')}
</CSV>
-->
</html>`;
}

function isLbsLikeRequest(pathname, reqBody, contentType) {
  if (pathname === '/mhweb/lbs.jsp') return true;
  if (pathname === '/mhweb/enterareas' || pathname === '/mhweb/enterareas.jsp') return true;
  if (!pathname.startsWith('/mhweb/') || reqBody.length === 0) return false;

  const form = parseFormBody(reqBody, contentType);
  return !!form['connection-id'];
}

function gameEndPage() {
  return directivePage('CRS-GAME-END', ['OK', `${BASE_URL}/index.jsp`]);
}

function errorPage(msg) {
  return directivePage('CRS-ERROR', ['NG', msg, `${BASE_URL}/index.jsp`]);
}

function createFreshSessid(userid) {
  let id;

  do {
    id = String(Math.floor(10000000 + Math.random() * 90000000));
  } while (getSession(id));

  upsertSession(id, {
    userid,
    handle: accounts[userid].handle || null,
    source: 'http-login-new'
  });

  return id;
}

let reqCount = 0;

function handleRequest(req, reqBody) {
  const parsedUrl = new URL(req.url, `http://${req.headers.host || SELF_HOST}`);
  const pathname = parsedUrl.pathname;
  const remoteIp = req.socket.remoteAddress;

  function startSession(userid) {
    const sessid = createFreshSessid(userid);

    accounts[userid].lastLogin = new Date().toISOString();
    delete accounts[userid].sessid;
    saveAccounts();

    upsertSession(sessid, {
      userid,
      ip: remoteIp,
      handle: accounts[userid].handle || null,
      lastHttpLogin: new Date().toISOString(),
      loginComplete: true
    });

    return sessid;
  }

  function finishBrowserAuth(userid, source) {
    const sessid = startSession(userid);
    markPendingOnlineFromLbs({ ip: remoteIp, sessid, userid });
    console.log(`[account] ${source}: ${userid}  sessid=${sessid}  ip=${remoteIp}  -> Login successful landing (SN@P armed)`);
    return startSessionLandingPage(sessid);
  }

  if (pathname.startsWith('/mhweb/assets/') && req.method === 'GET') {
    const fileName = path.basename(pathname);
    const safePath = path.join(WEB_ASSETS_DIR, fileName);

    if (!safePath.startsWith(WEB_ASSETS_DIR) || !fs.existsSync(safePath)) {
      return {
        status: 404,
        body: Buffer.from('Not found', 'utf8'),
        contentType: 'text/plain; charset=utf-8'
      };
    }

    const ext = path.extname(safePath).toLowerCase();
    const contentType = ext === '.png' ? 'image/png' : 'application/octet-stream';

    return {
      status: 200,
      body: fs.readFileSync(safePath),
      contentType
    };
  }

  if (pathname === '/mhweb/index.jsp') return topPage();

  if (pathname === '/mhweb/create.jsp' && req.method === 'GET') {
    return signupForm(null);
  }

  if (pathname === '/mhweb/login.jsp' && req.method === 'GET') {
    return loginForm(null);
  }

  if ((pathname === '/mhweb/startsession' || pathname === '/mhweb/startsession.jsp') && req.method === 'GET') {
    const sessid = sanitize(parsedUrl.searchParams.get('sessid'), 20);
    if (!sessid) return errorPage('Missing sessid');
    if (!getSession(sessid)) return errorPage('Invalid sessid');
    return gameStartPage(sessid);
  }

  if (pathname === '/mhweb/enterareas' || pathname === '/mhweb/enterareas.jsp') {
    if (req.method === 'GET') {
      const sessid = sanitize(parsedUrl.searchParams.get('sessid'), 20);
      return enterAreasPage(sessid);
    }
  }

  if (pathname === '/mhweb/lbs_info') {
    let sessid = '';

    if (req.method === 'POST' && reqBody.length > 0) {
      const form = parseFormBody(reqBody, req.headers['content-type']);
      sessid = sanitize(form['connection-id'] || form.sessid, 20);
    } else {
      sessid = sanitize(parsedUrl.searchParams.get('sessid'), 20);
    }

    console.log(`[lbs] ${req.method} /mhweb/lbs_info from ${remoteIp}  sessid=${sessid}  -> lbsInfoPage`);
    return lbsInfoPage(sessid);
  }

  if (pathname === '/mhweb/0' || pathname.startsWith('/mhweb/0?')) {
    const form = (req.method === 'POST' && reqBody.length > 0)
      ? parseFormBody(reqBody, req.headers['content-type'])
      : {};

    const clientConnId = form['connection-id'] || '';
    const clientUserId = form['user-id'] || '';

    console.log(`[mhweb/0] ${req.method} from ${remoteIp}  connection-id="${clientConnId}"  user-id="${clientUserId}"`);

    const variant = process.env.MHWEB0_VARIANT || 'lbs_info_default';

    switch (variant) {
      case 'minimal_ok':
        return `<html><head><!--CRS-LBS-INFO-GET-->\n<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1></head>\n<!--<CSV>"OK",</CSV>--></html>`;

      case 'game_start_4field': {
        const sid = sanitize(clientUserId, 14) || 'session';
        return gameStartPage(sid);
      }

      case 'empty':
        return '';

      case 'lbs_info_default':
      default:
        return lbsInfoPage(clientUserId || clientConnId);
    }
  }

  if (pathname === '/mhweb/logout.jsp') {
    return gameEndPage();
  }

  if (pathname === '/mhweb/create.jsp' && req.method === 'POST') {
    const form = parseFormBody(reqBody, req.headers['content-type']);
    const userid = sanitize(form.userid, 14);
    const password = sanitize(form.password, 14);

    if (userid.length < 3) return signupForm('User ID must be 3-14 chars');
    if (password.length < 4) return signupForm('Password must be 4-14 chars');
    if (accounts[userid]) return signupForm('User ID already exists');

    accounts[userid] = {
      userid,
      password,
      created: new Date().toISOString(),
      handle: userid
    };

    saveAccounts();

    const sessid = startSession(userid);
    markPendingOnlineFromLbs({ ip: remoteIp, sessid, userid });

    console.log(`[account] created: ${userid}  handle="${userid}"  sessid=${sessid}  -> COMP-SIGNUP response`);

    return signupCompletePage(sessid, userid);
  }

  if (pathname === '/mhweb/login.jsp' && req.method === 'POST') {
    const form = parseFormBody(reqBody, req.headers['content-type']);
    const userid = sanitize(form.userid, 14);
    const password = sanitize(form.password, 14);
    const acc = accounts[userid];

    if (!acc) return loginForm('User ID not found');
    if (acc.password !== password) return loginForm('Incorrect password');

    if (!acc.handle || acc.handle !== userid) {
      acc.handle = userid;
      saveAccounts();
    }

    console.log(`[account] login: ${userid}  handle="${userid}"`);
    return finishBrowserAuth(userid, 'login');
  }

  if (req.method === 'POST' && isLbsLikeRequest(pathname, reqBody, req.headers['content-type'])) {
    const form = parseFormBody(reqBody, req.headers['content-type']);
    const connectionId = sanitize(form['connection-id'], 20);
    const userId = sanitize(form['user-id'], 20);

    console.log(`[lbs] POST ${pathname} from ${remoteIp}  connection-id=${connectionId}  user-id=${userId}`);

    if (!connectionId) {
      return errorPage('Missing connection-id');
    }

    const session = getSession(connectionId);
    if (!session) {
      return errorPage('Invalid connection-id');
    }

    const resolvedUserId = userId || session.userid;

    if (!resolvedUserId) {
      return errorPage('Cannot resolve user-id');
    }

    if (userId && session.userid !== userId) {
      return errorPage('Session mismatch');
    }

    const resolvedHandle = accounts[resolvedUserId]?.handle || resolvedUserId;

    markPendingOnlineFromLbs({
      ip: remoteIp,
      sessid: connectionId,
      userid: resolvedUserId,
      handle: resolvedHandle
    });

    console.log(`[lbs] armed SN@P handoff for user=${resolvedUserId} handle=${resolvedHandle} sessid=${connectionId} ip=${remoteIp} host=${SNAP_HOST_PORT}`);

    pineAutoInject(resolvedHandle).catch(() => {});

    if (pathname === '/mhweb/enterareas' || pathname === '/mhweb/enterareas.jsp') {
      return enterAreasGameStartPage(connectionId);
    }

    return lbsInfoPage(connectionId);
  }

  if (pathname === '/mhweb/lbs.jsp' && req.method === 'GET') {
    const sessid = sanitize(parsedUrl.searchParams.get('sessid'), 20);
    return enterAreasPage(sessid);
  }

  return errorPage(`Unknown URL: ${pathname}`);
}

const server = http.createServer((req, res) => {
  const id = ++reqCount;
  const remote = `${req.socket.remoteAddress}:${req.socket.remotePort}`;
  const chunks = [];

  req.on('data', c => chunks.push(c));

  req.on('end', () => {
    const reqBody = Buffer.concat(chunks);
    const ts = Date.now();
    const tStart = process.hrtime.bigint();
    const isoTs = nowIsoMs();
    const hostPart = (req.headers.host || 'nohost').replace(/[:.]/g, '_');
    const urlPart = req.url.replace(/[^a-zA-Z0-9._-]/g, '_').slice(0, 40);
    const base = path.join(CAPTURES_DIR, `http_${id}_${hostPart}_${urlPart}_${ts}`);

    console.log(`\n${'='.repeat(60)}`);
    console.log(`[req ${id}] ${isoTs}  ${req.method} ${req.url}`);
    console.log(`[req ${id}] From:   ${remote}  Host: ${req.headers.host}  UA: ${req.headers['user-agent']}`);

    if (reqBody.length > 0) {
      console.log(`[req ${id}] Body (${reqBody.length} bytes)  hex=${toHex(reqBody)}`);
    }

    const reqLine = `${req.method} ${req.url} HTTP/${req.httpVersion}\r\n`;
    const headerLines =
      Object.entries(req.headers).map(([k, v]) => `${k}: ${v}`).join('\r\n') + '\r\n\r\n';

    const fullRequest = Buffer.concat([Buffer.from(reqLine + headerLines, 'latin1'), reqBody]);
    fs.writeFileSync(base + '.txt', fullRequest.toString('latin1'));

    if (reqBody.length > 0) {
      fs.writeFileSync(base + '.body.bin', reqBody);
    }

    let resBody;
    let statusCode = 200;
    let contentType = 'text/html; charset=iso-8859-1';

    try {
      resBody = handleRequest(req, reqBody);
    } catch (e) {
      console.log(`[req ${id}] handler error: ${e.message}`);
      resBody = errorPage(e.message);
    }

    const bodyDecoded = (() => {
      try {
        return parseFormBody(reqBody, req.headers['content-type']);
      } catch {
        return {};
      }
    })();

    function writeTrace(respBuf, respStatus, respCT, respBytes) {
      const tEnd = process.hrtime.bigint();
      const elapsedMs = Number(tEnd - tStart) / 1e6;

      appendTrace({
        ts: isoTs,
        id,
        method: req.method,
        url: req.url,
        host: req.headers.host || null,
        remote,
        headers: req.headers,
        reqBytes: reqBody.length,
        bodyHex: reqBody.length ? toHex(reqBody) : '',
        bodyDecoded,
        respStatus,
        respContentType: respCT,
        respBytes,
        respHash: respBytes ? sha1_8(respBuf) : '',
        elapsedMs: Number(elapsedMs.toFixed(3))
      });
    }

    if (resBody && typeof resBody === 'object' && Buffer.isBuffer(resBody.body)) {
      statusCode = resBody.status || 200;
      contentType = resBody.contentType || 'application/octet-stream';

      fs.writeFileSync(base + '.resp.bin', resBody.body);

      res.writeHead(statusCode, {
        'Content-Type': contentType,
        'Content-Length': resBody.body.length,
        'Connection': 'close'
      });

      res.end(resBody.body);

      console.log(`[req ${id}] -> ${statusCode}  ${contentType}  (${resBody.body.length} bytes)`);
      writeTrace(resBody.body, statusCode, contentType, resBody.body.length);
      return;
    }

    fs.writeFileSync(base + '.resp.html', resBody);

    const respBuf = Buffer.from(resBody, 'latin1');

    res.writeHead(statusCode, {
      'Content-Type': contentType,
      'Content-Length': respBuf.length,
      'Connection': 'close'
    });

    res.end(respBuf);

    console.log(`[req ${id}] -> 200 OK  (${respBuf.length} bytes)`);
    writeTrace(respBuf, statusCode, contentType, respBuf.length);
  });

  req.on('error', e => console.log(`[req ${id}] req error: ${e.message}`));
});

server.on('error', e => {
  if (e.code === 'EACCES') {
    console.log('ERROR: Permission denied on port 80. Run as Administrator.');
    process.exit(1);
  }

  console.log('Server error: ' + e.message);
});

server.listen(80, '0.0.0.0', () => {
  console.log('HTTP server listening on port 80');
  console.log(`Accounts loaded: ${Object.keys(accounts).length}`);
  console.log(`SN@P lobby     : ${SNAP_HOST_PORT}  (hex: ${SNAP_HEX_ADDR})`);
  console.log(`Captures       : ${CAPTURES_DIR}`);
  console.log('Ready.\n');
});