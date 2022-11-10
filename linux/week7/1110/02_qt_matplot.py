import os
import numpy as np
import matplotlib
import matplotlib.tri as mtri
import matplotlib.pyplot as plt
os.sys.path.append('./design/design_02.py')
from design.design_02 import Ui_MainWindow
from PySide6.QtWidgets import *
from matplotlib import pyplot
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg

plt.style.use('dark_background')
plt.style.available

class myapp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(myapp, self).__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.figure = pyplot.Figure()
        self.canvas = FigureCanvasQTAgg(self.figure)
        self.lay.addWidget(self.canvas)
        # self.graph1 = self.figure.add_subplot(1, 2, 1)
        # self.graph2 = self.figure.add_subplot(1, 2, 2)
        # self.graph3 = self.figure.add_subplot(1, 2, 1, projection='3d')
        # self.graph4 = self.figure.add_subplot(1, 2, 2, projection='3d')
        self.graph5 = self.figure.add_subplot(1, 2, 1, projection='3d')
        # self.graph6 = self.figure.add_subplot(1, 2, 2, projection='3d')
        # self.graph7 = self.figure.add_subplot(1, 2, 2, projection='3d')
        self.graph8 = self.figure.add_subplot(1, 2, 2, projection='3d')
        self.graph9 = None
        # plt.clf()

    def chart1(self):
        # line = [1, 2, 3]
        # self.graph1.plot(line, [10, 40, 50])
        # self.graph1.plot(line, [32, 35, 19])
        # self.graph1.plot(line, [4, 53, 76])
        # self.chart3()
        self.chart5()
        # self.chart9()
        self.canvas.draw()

    def chart2(self):
        # line = [1, 2, 3]
        # self.graph2.bar(line, [10, 50, 30])
        # self.chart4()
        # self.chart6()
        # self.chart7()
        self.chart8()
        self.canvas.draw()

    def chart3(self):
        # ==========
        # First plot
        # ==========

        # Make a mesh in the space of parameterisation variables u and v
        u = np.linspace(0, 2.0 * np.pi, endpoint=True, num=50)
        v = np.linspace(-0.5, 0.5, endpoint=True, num=10)
        u, v = np.meshgrid(u, v)
        u, v = u.flatten(), v.flatten()

        # This is the Mobius mapping, taking a u, v pair and returning an x, y, z
        # triple
        x = (1 + 0.5 * v * np.cos(u / 2.0)) * np.cos(u)
        y = (1 + 0.5 * v * np.cos(u / 2.0)) * np.sin(u)
        z = 0.5 * v * np.sin(u / 2.0)

        # Triangulate parameter space to determine the triangles
        tri = mtri.Triangulation(u, v)

        # Plot the surface.  The triangles in parameter space determine which x, y, z
        # points are connected by an edge.
        ax = self.graph3
        ax.plot_trisurf(x, y, z, triangles=tri.triangles, cmap=plt.cm.Spectral)
        ax.set_zlim(-1, 1)

    def chart4(self):
        # ===========
        # Second plot
        # ===========
        # Make parameter spaces radii and angles.
        n_angles = 36
        n_radii = 8
        min_radius = 0.25
        radii = np.linspace(min_radius, 0.95, n_radii)

        angles = np.linspace(0, 2 * np.pi, n_angles, endpoint=False)
        angles = np.repeat(angles[..., np.newaxis], n_radii, axis=1)
        angles[:, 1::2] += np.pi / n_angles

        # Map radius, angle pairs to x, y, z points.
        x = (radii * np.cos(angles)).flatten()
        y = (radii * np.sin(angles)).flatten()
        z = (np.cos(radii) * np.cos(3 * angles)).flatten()

        # Create the Triangulation; no triangles so Delaunay triangulation created.
        triang = mtri.Triangulation(x, y)

        # Mask off unwanted triangles.
        xmid = x[triang.triangles].mean(axis=1)
        ymid = y[triang.triangles].mean(axis=1)
        mask = xmid ** 2 + ymid ** 2 < min_radius ** 2
        triang.set_mask(mask)

        # Plot the surface.
        ax = self.graph4
        ax.plot_trisurf(triang, z, cmap=plt.cm.CMRmap)

    def chart5(self):
        def midpoints(x):
            sl = ()
            for i in range(x.ndim):
                x = (x[sl + np.index_exp[:-1]] + x[sl + np.index_exp[1:]]) / 2.0
                sl += np.index_exp[:]
            return x

        # prepare some coordinates, and attach rgb values to each
        r, g, b = np.indices((17, 17, 17)) / 16.0
        rc = midpoints(r)
        gc = midpoints(g)
        bc = midpoints(b)

        # define a sphere about [0.5, 0.5, 0.5]
        sphere = (rc - 0.5) ** 2 + (gc - 0.5) ** 2 + (bc - 0.5) ** 2 < 0.5 ** 2

        # combine the color components
        colors = np.zeros(sphere.shape + (3,))
        colors[..., 0] = rc
        colors[..., 1] = gc
        colors[..., 2] = bc

        # and plot everything
        ax = self.graph5
        ax.set_title("Before SSAFY", fontsize=15)
        ax.voxels(r, g, b, sphere,
                  facecolors=colors,
                  edgecolors=np.clip(2 * colors - 0.5, 0, 1),  # brighter
                  linewidth=0.5)
        ax.set(xlabel='r', ylabel='g', zlabel='b')
        ax.set_aspect('equal')

    def chart6(self):
        def explode(data):
            size = np.array(data.shape) * 2
            data_e = np.zeros(size - 1, dtype=data.dtype)
            data_e[::2, ::2, ::2] = data
            return data_e

        # build up the numpy logo
        n_voxels = np.zeros((4, 3, 4), dtype=bool)
        n_voxels[0, 0, :] = True
        n_voxels[-1, 0, :] = True
        n_voxels[1, 0, 2] = True
        n_voxels[2, 0, 1] = True
        facecolors = np.where(n_voxels, '#FFD65DC0', '#7A88CCC0')
        edgecolors = np.where(n_voxels, '#BFAB6E', '#7D84A6')
        filled = np.ones(n_voxels.shape)

        # upscale the above voxel image, leaving gaps
        filled_2 = explode(filled)
        fcolors_2 = explode(facecolors)
        ecolors_2 = explode(edgecolors)

        # Shrink the gaps
        x, y, z = np.indices(np.array(filled_2.shape) + 1).astype(float) // 2
        x[0::2, :, :] += 0.05
        y[:, 0::2, :] += 0.05
        z[:, :, 0::2] += 0.05
        x[1::2, :, :] += 0.95
        y[:, 1::2, :] += 0.95
        z[:, :, 1::2] += 0.95

        ax = self.graph6
        ax.voxels(x, y, z, filled_2, facecolors=fcolors_2, edgecolors=ecolors_2)
        ax.set_aspect('equal')

        plt.show()

    def chart7(self):
        def midpoints(x):
            sl = ()
            for i in range(x.ndim):
                x = (x[sl + np.index_exp[:-1]] + x[sl + np.index_exp[1:]]) / 2.0
                sl += np.index_exp[:]
            return x

        # prepare some coordinates, and attach rgb values to each
        r, theta, z = np.mgrid[0:1:11j, 0:np.pi * 2:25j, -0.5:0.5:11j]
        x = r * np.cos(theta)
        y = r * np.sin(theta)

        rc, thetac, zc = midpoints(r), midpoints(theta), midpoints(z)

        # define a wobbly torus about [0.7, *, 0]
        sphere = (rc - 0.7) ** 2 + (zc + 0.2 * np.cos(thetac * 2)) ** 2 < 0.2 ** 2

        # combine the color components
        hsv = np.zeros(sphere.shape + (3,))
        hsv[..., 0] = thetac / (np.pi * 2)
        hsv[..., 1] = rc
        hsv[..., 2] = zc + 0.5
        colors = matplotlib.colors.hsv_to_rgb(hsv)

        # and plot everything
        ax = self.graph7
        ax.voxels(x, y, z, sphere,
                  facecolors=colors,
                  edgecolors=np.clip(2 * colors - 0.5, 0, 1),  # brighter
                  linewidth=0.5)

        plt.show()

    def chart8(self):
        from mpl_toolkits.mplot3d import Axes3D
        from skimage import measure

        # Set up mesh
        n = 100

        x = np.linspace(-3, 3, n)
        y = np.linspace(-3, 3, n)
        z = np.linspace(-3, 3, n)
        X, Y, Z = np.meshgrid(x, y, z)

        # Create cardioid function
        def f_heart(x, y, z):
            F = 320 * ((-x ** 2 * z ** 3 - 9 * y ** 2 * z ** 3 / 80) +
                       (x ** 2 + 9 * y ** 2 / 4 + z ** 2 - 1) ** 3)
            return F

        # Obtain value to at every point in mesh
        vol = f_heart(X, Y, Z)

        # Extract a 2D surface mesh from a 3D volume (F=0)
        verts, faces, normals, values = measure.marching_cubes(vol, 0, spacing=(0.1, 0.1, 0.1))

        # Create a 3D figure
        ax = self.graph8
        # ax = self.figure.add_subplot(1, 2, 2, projection='3d')

        # Plot the surface
        ax.plot_trisurf(verts[:, 0], verts[:, 1], faces, verts[:, 2],
                        cmap='Spectral', lw=1)

        # Change the angle of view and title
        ax.view_init(15, -15)

        # ax.set_title(u"Made with ❤ (and Python)", fontsize=15) # if you have Python 3
        ax.set_title("After SSAFY", fontsize=15)

        # Show me some love ^^
        plt.show()

    def chart9(self):
        from matplotlib.collections import PolyCollection

        def frustum(left, right, bottom, top, znear, zfar):
            M = np.zeros((4, 4), dtype=np.float32)
            M[0, 0] = +2.0 * znear / (right - left)
            M[1, 1] = +2.0 * znear / (top - bottom)
            M[2, 2] = -(zfar + znear) / (zfar - znear)
            M[0, 2] = (right + left) / (right - left)
            M[2, 1] = (top + bottom) / (top - bottom)
            M[2, 3] = -2.0 * znear * zfar / (zfar - znear)
            M[3, 2] = -1.0
            return M

        def perspective(fovy, aspect, znear, zfar):
            h = np.tan(0.5 * np.radians(fovy)) * znear
            w = h * aspect
            return frustum(-w, w, -h, h, znear, zfar)

        def translate(x, y, z):
            return np.array([[1, 0, 0, x], [0, 1, 0, y],
                             [0, 0, 1, z], [0, 0, 0, 1]], dtype=float)

        def xrotate(theta):
            t = np.pi * theta / 180
            c, s = np.cos(t), np.sin(t)
            return np.array([[1, 0, 0, 0], [0, c, -s, 0],
                             [0, s, c, 0], [0, 0, 0, 1]], dtype=float)

        def yrotate(theta):
            t = np.pi * theta / 180
            c, s = np.cos(t), np.sin(t)
            return np.array([[c, 0, s, 0], [0, 1, 0, 0],
                             [-s, 0, c, 0], [0, 0, 0, 1]], dtype=float)

        V, F = [], []
        with open("bunny.obj") as f:
            for line in f.readlines():
                if line.startswith('#'):  continue
                values = line.split()
                if not values:            continue
                if values[0] == 'v':
                    V.append([float(x) for x in values[1:4]])
                elif values[0] == 'f':
                    F.append([int(x) for x in values[1:4]])

        V, F = np.array(V), np.array(F) - 1
        V = (V - (V.max(0) + V.min(0)) / 2) / max(V.max(0) - V.min(0))
        MVP = perspective(25, 1, 1, 100) @ translate(0, 0, -3.5) @ xrotate(20) @ yrotate(45)
        V = np.c_[V, np.ones(len(V))] @ MVP.T
        V /= V[:, 3].reshape(-1, 1)
        V = V[F]
        T = V[:, :, :2]
        Z = -V[:, :, 2].mean(axis=1)
        zmin, zmax = Z.min(), Z.max()
        Z = (Z - zmin) / (zmax - zmin)
        C = plt.get_cmap("magma")(Z)
        I = np.argsort(Z)
        T, C = T[I, :], C[I, :]

        ax = self.figure.add_axes([0, 0, 1, 1], xlim=[-1, +1], ylim=[-1, +1], aspect=1, frameon=False)
        self.graph9 = ax
        collection = PolyCollection(T, closed=True, linewidth=0.1, facecolor=C, edgecolor="black")
        ax.add_collection(collection)
        plt.show()

app = QApplication()
win = myapp()
win.show()
app.exec()