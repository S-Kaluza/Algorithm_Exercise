import matplotlib.pyplot as plt

files = open("/mnt/c/Users/szymo/Desktop/Algorytmy/lab08.03.2022/tekst.txt", "r")
tab = []
tab2 = []
neo = 128
for j in range(0, 10):
    tab.append(round((float)(files.readline().rstrip()), 6))
for j in range(0, 10):
    tab2.append(neo)
    neo *= 2

plt.plot(tab, tab2)
plt.ylabel("czasy wykonania")
plt.show()
files.close()