import numpy as np
import cv2
import matplotlib.pyplot as plt

def middle_five_box_area(img, col_split = 7, row_split = 3, draw_box = True):
    # col_split 은 홀수 추천. -> 3 개의 가운데 영역을 판단에 사용하기 때문
    height, width, channel = img.shape

    col_gap = width // col_split
    row_top_pos = int(height * (6/13)) # <- 7/13 은 체크 필요
    row_gap = (height - row_top_pos) // row_split
    
    box_gap = 20
    
    # 3 split for left, mid, right
    mid_idx = col_split // 2 
    box = {  
        'col':{
            'left'    : {'start': (mid_idx - 2) * col_gap - box_gap * 2, 
                         'end'  : (mid_idx - 1) * col_gap - box_gap * 2 - 1 },
            'leftmid' : {'start': (mid_idx - 1) * col_gap - box_gap, 
                         'end'  : (mid_idx    ) * col_gap - box_gap - 1 },
            'mid'     : {'start': (mid_idx    ) * col_gap, 
                         'end'  : (mid_idx + 1) * col_gap - 1 },
            'rightmid': {'start': (mid_idx + 1) * col_gap + box_gap, 
                         'end'  : (mid_idx + 2) * col_gap + box_gap - 1 },
            'right'   : {'start': (mid_idx + 2) * col_gap + box_gap * 2, 
                         'end'  : (mid_idx + 3) * col_gap + box_gap * 2 - 1 }
        },
        'row' : {
            'top'   : {'start': row_top_pos, 'end': row_top_pos + row_gap },
        }
    }
    
    # draw box on the img
    color = {
        'blue'  : (255, 0, 0),
        'green' : (0, 255, 0),
        'red'   : (0, 0, 255),
    }
    
    for pos in ['left','leftmid', 'mid', 'rightmid', 'right']:
        cv2.rectangle(img, 
                    (box['col'][pos]['start'], box['row']['top']['start']),
                    (box['col'][pos]['end'],   box['row']['top']['end']),
                    color['green'],
                    3
                    )
        
    return box

def line_status_check(box_area, p1, p2) -> int:
    # return current box index : 0, 1, 2, 3, 4
    
    row_max = max(p1[1], p2[1])
    row_min = min(p1[1], p2[1])
    
    col_max = max(p1[0], p2[0])
    col_min = min(p1[0], p2[0])
    
    # row check
    if box_area['row']['top']['start'] > row_max: return -1
    if box_area['row']['top']['end'] < row_max: return -1
    if box_area['row']['top']['start'] > row_min: return -1
    if box_area['row']['top']['end'] < row_min: return -1
       
    # if row is okay, then check col 
    for i, pos in enumerate(['left','leftmid', 'mid', 'rightmid', 'right']):
        if (pos == 'mid') : continue
        if box_area['col'][pos]['start'] <= col_max <= box_area['col'][pos]['end']:
            if box_area['col'][pos]['start'] <= col_min <= box_area['col'][pos]['end']:
                return i
            
    return -1   

def tracing(box_cnt):
    print(box_cnt)
    right_cnt = sum(box_cnt[3:])
    left_cnt = sum(box_cnt[:2])
    
    right_percent = int((right_cnt / (left_cnt + right_cnt)) * 100)
    left_percent = int((left_cnt / (left_cnt + right_cnt)) * 100)
    diff_percent = abs(right_percent - left_percent)
    
    if right_percent > left_percent:
        if diff_percent > 50:
            print('go right harder')
        elif 10 < diff_percent:
            print('go right')
        else:
            print('go straight')
    elif right_percent < left_percent:
        if diff_percent > 50:
            print('go left harder')
        elif 10 < diff_percent:
            print('go left')
        else:
            print('go straight')
    else:
        print("go straight")

def main():
    # cap = cv2.VideoCapture(0)
    # # cap.set(cv2.CAP_PROP_FPS, 60) # newly added code
    # # cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
    # # cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
    
    # while True:
    #     rval, frame = cap.read()
    #     if frame is not None:
    #         cv2.imshow('video', frame)
    #         plt.show()

    #     if cv2.waitKey(1) & 0xFF == ord('q'):
    #         break
    
    # cap.release()
    # # cv2.imshow("output", output)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()
    
    src = cv2.imread("linux/week9/road.png")    
    edges = cv2.Canny(src, 5000, 1500, apertureSize = 5, L2gradient = True)
    gray = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)
    minLineLength = 100
    maxLineGap = 0

    lines = cv2.HoughLinesP(edges,1,np.pi/360,100,minLineLength,maxLineGap)

    ##
    box_area = middle_five_box_area(src, col_split = 7, row_split = 3, draw_box = True)
    box_cnt = [ 0 for _ in range(5)]
    
    lines = cv2.HoughLinesP(edges,1,np.pi/360,100,minLineLength,maxLineGap)
    for i in range(len(lines)):
        for x1,y1,x2,y2 in lines[i]:

            ##
            box_idx = line_status_check(box_area, (x1, y1), (x2, y2))
            if(box_idx != -1):
                box_cnt[box_idx] += 1
                cv2.line(src, (x1,y1), (x2,y2), (0,0,255),3)
                # print(f'x1,y1:{x1},{y1}', end="--")
                # print(f'x2,y2:{x2},{y2}')

    tracing(box_cnt)
    
    cv2.imshow("src", src)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


main()