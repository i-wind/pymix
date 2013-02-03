'''A sample of Python TCP client'''

import socket

HOST = '127.0.0.1'        # The localhost
PORT = 50007              # The same port as used by the server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

print 'Send to server', '\'Hello, world\''
s.send('Hello, world')

data = s.recv(1024)
print 'Received back', repr(data)

s.close()
print 'Client closed.'

