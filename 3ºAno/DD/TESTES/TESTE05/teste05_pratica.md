# Experiência da aula

- Colocamos uma ACL no R2 para deixarmos apenas sairem IPs públicos permitidos na empresa

```console
conf t
ip access-list standard PUBLIC_ADDR_SPACE
permit 194.65.52.0 0.0.0.7 log
deny any log

int e0/1
ip access-group PUBLIC_ADDR_SPACE out
```

- Instalamos uma *discard route* no R2 para o espaço de endereçamento da empresa para que caso o R2 receba trafego de fora para aquela rede, ele envia para null0

```console
conf t
ip route 194.65.52.0 255.255.255.248 null0
```

- No R2 criamos uma ACL para depois configurarmos o PAT

```console
ip access-list 1 permit 192.168.100.0 255.255.255.0
ip access-list 2 permit 192.168.200.0 255.255.255.0

ip nat inside source list 1 pool NATPOOL_NETA overload
ip nat inside source list 2 pool NATPOOL_NETA overload

int e0/0
ip nat inside
```
