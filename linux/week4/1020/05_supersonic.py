from time import sleep

def supersonic():
    from gpiozero import DistanceSensor
    # DistanceSensor([Echo], [Trig])
    # cm: f'{sensor.distance*100:.0f}'
    sensor = DistanceSensor(23, 24)
    return int(sensor.distance*100)
    
def count_pass():
    near_flag = 0
    cnt = 0
    flag_name = 'nothing'
    while True:
        if supersonic() <= 5:
            near_flag = 1
            flag_name = 'passed'
        else:
            if near_flag:
                cnt += 1 
                near_flag = 0
                flag_name = 'nothing'
        
        print(f'\r{flag_name}, cnt[{cnt}]', end='', flush=True)

def main():
    count_pass()


main()