const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', (ws) => {
  console.log('Cliente conectado');

  ws.on('message', (message) => {
    console.log(`Mensaje recibido: ${message}`);
    // processing and sending messages back to clients
  });

  ws.on('close', () => {
    console.log('Cliente desconectado');
  });
});
