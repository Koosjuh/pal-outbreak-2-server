import http from 'node:http';

const MAX_REQUEST_BODY = 64 * 1024;

function csv(fields) {
  return `${fields.map((field) => `"${String(field).replaceAll('"', '""')}"`).join(',')},`;
}

function htmlBuffer(value) {
  return Buffer.from(value, 'latin1');
}

function escapeHtml(value) {
  return String(value)
    .replaceAll('&', '&amp;')
    .replaceAll('<', '&lt;')
    .replaceAll('>', '&gt;')
    .replaceAll('"', '&quot;');
}

function parseForm(body, contentType) {
  if (!String(contentType ?? '').toLowerCase().startsWith('application/x-www-form-urlencoded')) {
    return {};
  }
  return Object.fromEntries(new URLSearchParams(body.toString('latin1')));
}

function remoteAddress(request) {
  const address = request.socket.remoteAddress ?? '';
  return address.startsWith('::ffff:') ? address.slice(7) : address;
}

/**
 * Carry an observed DNAS token forward through the pages this server renders.
 *
 * Capture evidence (R-020, `docs/evidence/traces/protocol_trace.ndjson`) shows
 * the client presenting the token exactly once over HTTP, on
 * `GET /mhweb/index.jsp?DNAS=<base64>`, and then requesting `login.jsp` and
 * POSTing to it with nothing that links those requests back to it. Every
 * response also sets `Connection: close`, so there is no keep-alive to correlate
 * on either.
 *
 * Correlating by source address would fail exactly where it matters - two
 * consoles behind one NAT - so instead this server threads the token through its
 * OWN links and form actions, and the POST that creates the session carries it
 * back. That is an implementation security control, not reproduced protocol
 * behaviour: V1 did not propagate it, and whether the PS2 browser preserves a
 * query string on a form action is untested until a real client runs. If the
 * token does not come back, nothing is bound and the later TCP association fails
 * closed rather than guessing.
 */
function dnasQuery(dnasToken) {
  return dnasToken == null ? '' : `?DNAS=${encodeURIComponent(dnasToken)}`;
}

/**
 * The token for this request: its own query string, else the page it came from.
 *
 * The `Referer` fallback is not a guess. In every captured session the client
 * sends `GET /mhweb/login.jsp` with
 * `referer: http://.../mhweb/index.jsp?DNAS=<token>`, so the client demonstrably
 * carries the previous page's full URL, query string included. That is captured
 * in-band evidence for propagation, and it is what makes threading the token
 * through this server's own links workable rather than hopeful.
 */
function readDnasToken(request, url) {
  const direct = url.searchParams.get('DNAS');
  if (direct != null && direct !== '') return direct;
  const referer = request.headers.referer;
  if (typeof referer !== 'string' || referer === '') return null;
  try {
    return new URL(referer, 'http://placeholder.invalid').searchParams.get('DNAS');
  } catch {
    return null;
  }
}

function renderIndex(baseUrl, message = '', dnasToken = null) {
  const query = dnasQuery(dnasToken);
  return `<html><head><META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1></head>
<body><h1>Resident Evil Outbreak File #2</h1>${message ? `<p>${escapeHtml(message)}</p>` : ''}
<p><a href="${baseUrl}/create.jsp${query}">MAKE AN ACCOUNT</a></p>
<p><a href="${baseUrl}/login.jsp${query}">LOGIN</a></p></body></html>`;
}

function renderForm(baseUrl, kind, message = '', dnasToken = null) {
  const create = kind === 'create';
  return `<html><head><META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1></head>
<body><h1>${create ? 'Make an account' : 'Login'}</h1>
${message ? `<p>${escapeHtml(message)}</p>` : ''}
<form method="POST" action="${baseUrl}/${kind}.jsp${dnasQuery(dnasToken)}">
<!--INPUT-IDS--><input type="text" name="userid" maxlength="10">
<!--INPUT-PWD--><input type="password" name="password" maxlength="14">
<input type="submit" value="${create ? 'CREATE' : 'LOGIN'}">
</form></body></html>`;
}

export function renderAuthComplete({ baseUrl, userid, connectionId, action }) {
  const startUrl = `${baseUrl}/startsession?sessid=${connectionId}`;
  const title = action === 'create' ? 'Account created successfully.' : 'Login successful.';
  return `<html><head><!--COMP-SIGNUP-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1></head>
<body><h1>${title}</h1>
<p>Login Name: ${escapeHtml(userid)}</p>
<p><a href="${startUrl}">Enter Lobbies</a></p>
<p><!--INPUT-IDS-->${userid}\x00<br></p>
</body></html>`;
}

export function renderGameStart({ baseUrl, connectionId }) {
  return `<html><head><!--CRS-GAME-START-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--result--><!--connection id--><!--start the game url--><!--exit game url-->
<!--<CSV>${csv([
    'OK',
    connectionId,
    `${baseUrl}/lbs.jsp`,
    `${baseUrl}/logout.jsp`
  ])}</CSV>-->
</html>`;
}

export function renderLbsInfo({
  snapHost,
  snapPort,
  descriptiveHexAddress = '000000000000',
  lobbyName = 'PAL Lobby',
  message = 'Welcome to Resident Evil Outbreak File #2.'
}) {
  return `<html><head><!--CRS-LBS-INFO-GET-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head>
<!--
<CSV>
${csv(['OK'])}
${csv([`${snapHost}:${snapPort}`])}
${csv(['0'])}
${csv(['999'])}
${csv([`${descriptiveHexAddress},${lobbyName}`])}
${csv([`<BODY>${message}<END>`])}
${csv(['  '])}
</CSV>
-->
</html>`;
}

function renderDirective(name, fields) {
  return `<html><head><!--${name}-->
<META HTTP-EQUIV=Content-Type CONTENT=text/html;CHARSET=iso-8859-1>
</head><!--<CSV>${csv(fields)}</CSV>--></html>`;
}

async function readBody(request) {
  const chunks = [];
  let length = 0;
  for await (const chunk of request) {
    length += chunk.length;
    if (length > MAX_REQUEST_BODY) {
      const error = new Error('request body too large');
      error.statusCode = 413;
      throw error;
    }
    chunks.push(chunk);
  }
  return Buffer.concat(chunks);
}

export function createWebService({
  accountRepository,
  sessionRegistry,
  selfHost,
  snapHost,
  snapPort = 10127,
  descriptiveHexAddress = '000000000000',
  logger = () => {},
  onSessionEstablished = null,
  onLobbyProvisioned = null,
  // Display strings the operator owns. They are deliberately not defaulted here:
  // the values V1 sent are V1's, and must not become production content by
  // being the convenient fallback.
  lobbyName,
  welcomeMessage
}) {
  if (!accountRepository || !sessionRegistry) {
    throw new Error('accountRepository and sessionRegistry are required');
  }
  if (onSessionEstablished != null && typeof onSessionEstablished !== 'function') {
    throw new TypeError('onSessionEstablished must be a function when provided');
  }
  if (onLobbyProvisioned != null && typeof onLobbyProvisioned !== 'function') {
    throw new TypeError('onLobbyProvisioned must be a function when provided');
  }
  const baseUrl = `http://${selfHost}/mhweb`;

  /**
   * Bind a freshly authenticated session to the DNAS token that arrived with the
   * request that created it. A token that is absent or malformed binds nothing;
   * the TCP side then refuses to associate rather than assuming an identity.
   */
  function establishSession({ session, dnasToken, remote, action }) {
    if (onSessionEstablished == null) return;
    try {
      onSessionEstablished({
        sessionConnectionId: session.connectionId,
        userid: session.userid,
        dnasToken,
        remote,
        action
      });
    } catch (error) {
      logger({
        event: 'session-binding-failed',
        action,
        remoteAddress: remote,
        error: error.message,
        errorCode: error.code ?? null
      });
    }
  }

  return http.createServer(async (request, response) => {
    let statusCode = 200;
    let rendered;
    try {
      const body = await readBody(request);
      const url = new URL(request.url, `http://${request.headers.host || selfHost}`);
      const path = url.pathname;
      const remote = remoteAddress(request);
      // Opaque here: the token is threaded through this server's own pages and
      // handed to the identity registry, which is what validates it.
      const dnasToken = readDnasToken(request, url);

      if (
        request.method === 'GET' &&
        (path === '/' || path === '/mhweb/' || path === '/mhweb/index.jsp')
      ) {
        rendered = renderIndex(baseUrl, '', dnasToken);
      } else if (request.method === 'GET' && path === '/mhweb/create.jsp') {
        rendered = renderForm(baseUrl, 'create', '', dnasToken);
      } else if (request.method === 'GET' && path === '/mhweb/login.jsp') {
        rendered = renderForm(baseUrl, 'login', '', dnasToken);
      } else if (request.method === 'POST' && path === '/mhweb/create.jsp') {
        const form = parseForm(body, request.headers['content-type']);
        try {
          // Only the fields the sign-up form actually offers. Forwarding the
          // whole parsed body would let a crafted request set a display name
          // through a field no page emits.
          const account = accountRepository.create({
            userid: form.userid,
            password: form.password
          });
          const session = sessionRegistry.create({ account, remoteAddress: remote });
          establishSession({ session, dnasToken, remote, action: 'create' });
          rendered = renderAuthComplete({
            baseUrl,
            userid: account.userid,
            connectionId: session.connectionId,
            action: 'create'
          });
        } catch (error) {
          rendered = renderForm(baseUrl, 'create', error.code ?? 'ACCOUNT ERROR', dnasToken);
        }
      } else if (request.method === 'POST' && path === '/mhweb/login.jsp') {
        const form = parseForm(body, request.headers['content-type']);
        let account = null;
        try {
          account = accountRepository.authenticate(form.userid, form.password);
        } catch {
          // Invalid input and wrong credentials intentionally share one client-visible result.
        }
        if (!account) {
          rendered = renderForm(baseUrl, 'login', 'BAD LOGIN', dnasToken);
        } else {
          const session = sessionRegistry.create({ account, remoteAddress: remote });
          establishSession({ session, dnasToken, remote, action: 'login' });
          rendered = renderAuthComplete({
            baseUrl,
            userid: account.userid,
            connectionId: session.connectionId,
            action: 'login'
          });
        }
      } else if (
        request.method === 'GET' &&
        (path === '/mhweb/startsession' || path === '/mhweb/startsession.jsp')
      ) {
        const connectionId = url.searchParams.get('sessid') ?? '';
        const session = sessionRegistry.get(connectionId);
        rendered = session
          ? renderGameStart({ baseUrl, connectionId })
          : renderDirective('CRS-ERROR', ['NG', 'BAD SESSION', `${baseUrl}/index.jsp`]);
      } else if (path === '/mhweb/lbs.jsp') {
        const form =
          request.method === 'POST' ? parseForm(body, request.headers['content-type']) : {};
        const connectionId =
          form['connection-id'] ?? form.sessid ?? url.searchParams.get('sessid') ?? '';
        const session = sessionRegistry.markLobbyProvisioned(connectionId, remote);
        if (session && onLobbyProvisioned != null) {
          // The client takes the SN@P endpoint from this response and opens its
          // lobby connection next, so this is the moment its TCP 10127
          // connection stops being a boot-auth one.
          try {
            onLobbyProvisioned({
              remote,
              sessionConnectionId: session.connectionId,
              userid: session.userid
            });
          } catch (error) {
            logger({ event: 'lobby-arming-failed', remoteAddress: remote, error: error.message });
          }
        }
        rendered = session
          ? renderLbsInfo({
            snapHost,
            snapPort,
            descriptiveHexAddress,
            ...(lobbyName == null ? {} : { lobbyName }),
            ...(welcomeMessage == null ? {} : { message: welcomeMessage })
          })
          : renderDirective('CRS-ERROR', ['NG', 'BAD LBS SESSION', `${baseUrl}/index.jsp`]);
      } else if (path === '/mhweb/logout.jsp') {
        rendered = renderDirective('CRS-GAME-END', ['OK', `${baseUrl}/index.jsp`]);
      } else {
        statusCode = 404;
        rendered = renderDirective('CRS-ERROR', [
          'NG',
          `UNKNOWN ${path}`,
          `${baseUrl}/index.jsp`
        ]);
      }

      logger({
        method: request.method,
        path,
        remoteAddress: remote,
        statusCode
      });
    } catch (error) {
      statusCode = error.statusCode ?? 500;
      rendered = renderDirective('CRS-ERROR', ['NG', error.message, `${baseUrl}/index.jsp`]);
      logger({ error: error.message, statusCode });
    }

    const encoded = htmlBuffer(rendered);
    response.writeHead(statusCode, {
      'Content-Type': 'text/html; charset=iso-8859-1',
      'Content-Length': encoded.length,
      Connection: 'close'
    });
    response.end(encoded);
  });
}

