const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

const rooms = {}; // Store active rooms
let roomCounter = 1; // Unique ID for each room

wss.on('connection', (ws) => {
  // Assign player to an existing room or create room
  let room = findAvailableRoom();
  ws.room = room;
  joinRoom(room, ws);

  ws.on('message', (message) => {
    broadcastMessage(room, message, ws);
  });

  ws.on('close', () => {
    leaveRoom(room, ws);
  });
});

function findAvailableRoom() {
  for (const room in rooms) {
    if (rooms[room].length < 2) {
      return room;
    }
  }
  const newRoom = `Room-${roomCounter}`;
  roomCounter++;
  rooms[newRoom] = [];
  return newRoom;
}

function joinRoom(room, ws) {
  rooms[room].push(ws);
  if (rooms[room].length === 2) {
    // 2 players is enough. Start game
    startGame(room);
  }
}

function broadcastMessage(room, message, sender) {
  const receivers = rooms[room].filter((client) => client !== sender);
  receivers.forEach((client) => {
    client.send(message);
  });
}

function leaveRoom(room, ws) {
  rooms[room] = rooms[room].filter((client) => client !== ws);
  if (rooms[room].length === 0) {
    // No players left? Delete room
    delete rooms[room];
  }
}

function startGame(room) {
  // Start game on a specific room
  // Game logic and chat/communication between players
}
