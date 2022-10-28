import math

f = open("sinerom.mem","w")
for i in range(256):
    v = int(math.cos(2*math.pi*i/256)*127+127)
    if (i+1)%16 == 0:
        s = "{hex:2X}\n"
    else:
        s = "{hex:2X} "
    f.write(s.format(hex=v))

f.close()
