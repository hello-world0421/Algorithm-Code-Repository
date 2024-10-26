def kaprekar_routine(num: int) -> None:
    if len(set(str(num))) == 1 and len(str(num)) == 4:
        print(f"{num:04d} - {num:04d} = 0000")
        return
    
    if num == 6174:
        num_str: str = f"{num:04d}"
        num_asc: str = ''.join(sorted(num_str))
        num_desc: str = ''.join(sorted(num_str, reverse=True))

        print(f"{num_desc} - {num_asc} = {num_str}")
        return

    while num != 6174:
        num_str: str = f"{num:04d}"
        num_asc: str = ''.join(sorted(num_str))
        num_desc: str = ''.join(sorted(num_str, reverse=True))

        num: int = int(num_desc) - int(num_asc)
        print(f"{num_desc} - {num_asc} = {num:04d}")
    return


num: int = int(input())
kaprekar_routine(num)
