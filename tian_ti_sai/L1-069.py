cars = list(map(int, input().split()))
press = [abs(car-max(cars[0:4])) for car in cars[0:4]]
if max(press) <= cars[5] and len([car for car in cars[0:4] if car < cars[4]]) == 0:
    print("Normal")

elif len([a for a in press if a > cars[5]]) == 1 or len([car for car in cars[0:4] if car < cars[4]]) == 1:
    if len([a for a in press if a > cars[5]]) == 1:
        print(f"Warning: please check #{press.index(max(press))+1}!")
    elif len([car for car in cars[0:4] if car < cars[4]]) == 1:
        print(f"Warning: please check #{cars.index(min(cars[0:4]))+1}!")

elif len([a for a in press if a > cars[5]]) >= 2 or len([car for car in cars[0:4] if car < cars[4]]) >= 2:
    print("Warning: please check all the tires!")
