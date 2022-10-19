from sense_hat import SenseHat 
# from sense_emu import SenseHat
from signal import pause
from time import sleep
from collections import deque

sense = SenseHat()

O = [0, 0, 0]
X = [255, 255, 255]

wall2 = [
    ['O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'],
    ['O', 'X', 'X', 'X', 'X', 'O', 'X', 'O'],
    ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
    ['O', 'X', 'X', 'X', 'X', 'O', 'X', 'O'],
    ['O', 'O', 'X', 'O', 'O', 'O', 'X', 'O'],
    ['O', 'O', 'X', 'O', 'X', 'X', 'X', 'O'],
    ['O', 'X', 'X', 'O', 'O', 'O', 'O', 'O'],
    ['O', 'O', 'O', 'O', 'X', 'X', 'X', 'O']
]

wall = [
    O, X, O, O, O, O, O, O,
    O, X, X, X, X, O, X, O,
    O, O, O, O, O, O, O, O,
    O, X, X, X, X, O, X, O,
    O, O, X, O, O, O, X, O,
    O, O, X, O, X, X, X, O,
    O, X, X, O, O, O, O, O,
    O, O, O, O, X, X, X, O
]

paths = {
    'path': [
                [(1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0), (7, 0), (7, 1), (7, 2), (7, 3), (7, 4), (6, 4), (6, 5), (6, 6), (6, 7)],
                [(1, 0), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (3, 5), (4, 5), (4, 4), (4, 3), (5, 3), (6, 3), (6, 4), (6, 5), (6, 6), (6, 7)],
                [(1, 0), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6), (2, 7), (3, 7), (4, 7), (5, 7), (6, 7)],
                [(1, 0), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (1, 5), (0, 5), (0, 6), (0, 7), (1, 7), (2, 7), (3, 7), (4, 7), (5, 7), (6, 7)]
            ],

    'wall': [
                (0, 1), (1, 1), (1, 2), (1, 3), (1, 4),  (1, 6), 
                (3, 6), (4, 6),
                (3, 1), (3, 2), (3, 3), (3, 4), (4, 2), 
                (5, 2), (5, 6), (5, 5), (5, 4),
                (6, 1), (6, 2),
                (7, 4), (7, 5), (7, 6)
            ]
}



class Dot():
    def __init__(self):
        self.row = 0
        self.col = 0
        self.z = 7
        self.dR = 0
        self.dC = 0
        self.dZ = 0

    def set_pos(self, row, col):
        self.row = row
        self.col = col
    
    def step(self):
        sense.set_pixel(self.col, self.row, 0, 0, 0)
        sense.set_pixel(self.col, self.row, 255, 0, 255)

    def get_pos(self):
        return self.row, self.col

    def print_pos(self):
        print(f"[row, col]:[{self.row}, {self.col}]")

    def set_diff(self, print_option = 0):
        acceleration = sense.get_accelerometer_raw()
        self.dC = round(acceleration['x'], 0)
        self.dR = round(acceleration['y'], 0)
        self.dZ = round(acceleration['z'], 0 )

        if print_option:
            print(f"x={self.dC}, y={self.dR}, z={self.dZ}")

    def clamp(self, value, min_value=0, max_value=7):
        return min(max_value, max(min_value, value))

    def move_dot(self):
        now_row = self.row
        now_col = self.col
        next_row = int(self.clamp(self.row + self.dR))
        next_col = int(self.clamp(self.col + self.dC))

        if wall[convert2D21D(next_row, next_col)] != X:
            self.row = next_row
            self.col = next_col

        sense.set_pixel(now_col, now_row, 0, 0, 0)
        sense.set_pixel(self.col, self.row, 255, 0, 255)

    def set_path(self, row, col):
        self.path.append([row, col])

def convert_row_col(row, col):
    #  row(y), col(x)
    #  y = -x + 7
    return 7 - col, 7 - row

def display_off():
    global sense
    sense.low_light = False
    sense.clear(0, 0, 0)

def display_wall():
    global wall, sense
    display_position('wall', paths['wall'])

def display_position(mode = 'path', path_list = []):
    color_code = {
        'path': [255, 0, 0],
        'wall': [125, 125, 125]
    }

    for pos in path_list:
        if type(pos) == tuple:
            # row, col = convert_row_col(pos[0], pos[1])
            sense.set_pixel(pos[1], pos[0], 
                            color_code[mode][0], 
                            color_code[mode][1], 
                            color_code[mode][2])

def convert2D21D(row, col):
    return row * 8 + col

dy = [-1,0,1,0]
dx = [0,1,0,-1]

def getShortPath(start_y, start_x):

   visited = [[0]*8 for _ in range(8)]

   q = deque()
   q.append((start_y, start_x, [(start_y, start_x)]))
   visited[start_y][start_x] = 1

   while q:
       y, x, path = q.popleft()

       if (y, x) == (7, 7):
            return path

       for i in range(4):
           ny = y + dy[i]
           nx = x + dx[i]
      
           if(ny < 0 or ny >= 8 or nx < 0 or nx >= 8):
               continue
       
           if(wall2[ny][nx] == 'X'):
               continue

           if(visited[ny][nx] > 0):
               continue

           visited[ny][nx] = visited[y][x] + 1

           pa = [p for p in path]
           pa.append((ny, nx))
           q.append((ny, nx, pa))

def draw(start_y, start_x):
    sense.set_pixels(wall)
    path = getShortPath(start_y, start_x)
    start = path[0]   
    route = path[1:-1]

    sense.set_pixel(start[1], start[0], 0, 255, 0)
    for p in route:
        sense.set_pixel(p[1], p[0], 255, 0, 0)
    sense.set_pixel(7, 7, 0, 255, 0)

def problem_1_2():
    global wall, sense
    sense.show_message("1,2", 0.3 ,text_colour=[255, 255, 0])

    dot = Dot()
    # display_wall()
    sense.set_pixels(wall)

    while True:
        dot.set_diff()
        dot.move_dot()
        dot.print_pos()
        # draw(dot.row, dot.col)
        sleep(.1)

def problem_3():
    sense.show_message("3", 0.3 ,text_colour=[255, 255, 0])
    sense.clear()
    start = [0, 0, 'S']
    finish = [7, 7, 'F']
    
    mode = 'path'
    for p in paths[mode]:
        sense.set_pixel(start[0], start[1], 0, 255, 0)
        sense.set_pixel(finish[0], finish[1], 0, 255, 0)
        display_wall()
        # display_position('wall', paths['wall'])
        display_position(mode, p)
        sleep(1)
        sense.clear()

    de = 1

def problem_4():
    sense.show_message("4", 0.3 ,text_colour=[255, 255, 0])
    sense.set_pixels(wall)
    start_y, start_x = 0, 0
    
    draw(start_y, start_x)

    dot = Dot()
    dot.row = start_y
    dot.col = start_x
        
    while True:
        dot.set_diff()
        dot.move_dot()
        dot.print_pos()
        draw(dot.row, dot.col)
        sleep(0.1)
        if (dot.row == 7 and dot.col == 7):
            sense.clear()
            sense.show_message("!! GAME OVER !!")
            return


def main():
    global sense

    display_off()
    sense.low_light = True

    # problem_1_2()
    problem_3()
    problem_4()
   

main()