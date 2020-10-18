def wait(s):
    s=s-1
    return s

def signal(s):
    s=s+1
    return s

full=0
mutex=1
empty=3
x=0
def producer():
    global mutex
    global full
    global empty
    global x
    mutex=wait(mutex)
    full=signal(full)
    empty=wait(empty)
    x=x+1
    print("Producer produces", x)
    mutex = signal(mutex)

def consumer():
    global mutex
    global full
    global empty
    global x
    mutex = wait(mutex)
    full = wait(full)
    empty = signal(empty)
    print("Consumer consumes", x)
    x=x-1
    mutex = signal(mutex)

while(True):
    print("\n1:Producer \n2:Consumer \n3:Exit")
    n=int(input("Enter your choice"))
    if n==1:
        if mutex==1 and empty!=0:
            producer()
        else:
            print("Buffer Is Full")
    elif n==2:
        if mutex==1 and full!=0:
            consumer()
        else:
            print("Buffer is empty")
    elif n==3:
        exit(0)
