m, n, q = map(int, input().split())

password: dict[str, str] = {}
for _ in range(m):
    pub, pri = input().split()
    password[pri] = pub

ipv4: dict[str, dict[str, list[str]]] = {}
for _ in range(n):
    ip, cnt = input().split()
    for _ in range(int(cnt)):
        user, t, *pub = input().split()
        if ip not in ipv4.keys():
            ipv4[ip] = {}
        ipv4[ip][user] = pub

for _ in range(q):
    user, ip, pri = input().split()
    ok = False
    if ip in ipv4.keys() and user in ipv4[ip].keys() and password[pri] in ipv4[ip][user]:
        ok = True
    print('Yes') if ok else print('No')