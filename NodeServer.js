const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

let code = [1, 2, 4, 4]; // Código a adivinar
let attempts = 0;
const maxAttempts = 10;

wss.on('connection', (ws) => {
  attempts = 0;
  ws.send(JSON.stringify({ type: "message", content: "¡Jugador conectado!" }));

  ws.on('message', (message) => {
    const guess = message.split("").map((digit) => parseInt(digit, 10));
    attempts++;

    let correct = 0;
    let approximation = 0;

    for (let i = 0; i < 4; i++) {
      if (guess[i] === code[i]) {
        correct++;
      } else if (code.includes(guess[i])) {
        approximation++;
      }
    }

    ws.send(JSON.stringify({ type: "results", correct, approximation }));

    if (correct === 4) {
      ws.send(JSON.stringify({ type: "gameover", message: "¡ENHORABUENA! Has adivinado el código." }));
      ws.close();
    } else if (attempts >= maxAttempts) {
      ws.send(JSON.stringify({ type: "gameover", message: "LO SIENTO. No has adivinado el código. Inténtalo de nuevo." }));
      ws.close();
    }
  });
});
