v = [[a, i, j, a, i+1, j, a, i, j+1, a, i+1, j+1, a, i][0:12] for a in [0,3] for i in range(3) for j in range(3)] + \
    [[a, i, j, a, i+1, j, a, i, j+1, a, i+1, j+1, a, i][1:13] for a in [0,3] for i in range(3) for j in range(3)] + \
    [[a, i, j, a, i+1, j, a, i, j+1, a, i+1, j+1, a, i][2:14] for a in [0,3] for i in range(3) for j in range(3)]

i = [[r,r+1,r+2,r+1,r+2,r+3]for r in range(0,54*4,4)]

print(str(v).replace("]","").replace("[","\n"))