import asyncio, time

async def function1(delay, what):
    await asyncio.sleep(delay)
    print(f'this is {function1.__name__}, {what}')

async def main():
    print(f'this is {main.__name__}')

    await asyncio.gather( function1(4, "- delay 4"), function1(5, "- delay 5"))
    print(f'finished at {time.strftime(f"%X")}')

asyncio.run(main())