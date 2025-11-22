pylab inline
import matplotlib.pyploy as plt 
from mpl.toolkits.mplot3d import Axes3D
x = Linspace(0, 5, 20)
fig, ax = plt.subplots(facecolor='w', edgecolor=('k'))
ax.plot(x, sin(x), marker="o", color="r", linestyle='None')
ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend(["y = x**2"])
plt.title('Puntos')
plt.show()
fig.savefig("grafica.png")
