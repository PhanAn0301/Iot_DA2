from .extention import socketIO

@socketio.on("connect")
def handle_connect():
    print('Client')