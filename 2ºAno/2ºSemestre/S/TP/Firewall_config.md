# Rede Docentes e Externos


## Docentes

TIRAR APONTAMENTO DAS ACLS E EXPLICAR EM BAIXO
    
### Explicação

* Usamos a CBAC

* Permitimos que o Docente1 apenas faça pings para fora

* Aplicamos a ACL na F0/0 no sentido inbound para permitir o trafego
icmp, udp e tcp para fora e negamos tudo o resto

* Aplicamos a ACL na F0/1 no sentido inboud para negar todo o trafego
vindo de fora, exceto da DeepZone

* Aplicamos o `ip inspect F0/0_IN in` na interface F0/0 no sentido inboud para fazer
a inspeção dos pacotes



## Externos

TIRAR APONTAMENTO DAS ACLS E EXPLICAR EM BAIXO

### Explicação

Fazemos anti spoofing para todo o lado , internamente para fora
Permitimos echo replys de todo os lado mas nao permitimos echo requests
Permitimos que a deepzone aceda por telnet e ssh e faça pings e negamos tudo o resto

O Docente1 e o Externo1 só conseguem pingar mais nada
A deepzone consegue pingar para o Docente1 Docentes, Externo1 e Externos e consegue fazer telnet para o Docentes e Externos
O Docentes consegue usar todo o protocolo IP assim como o Externos

# Privilege level do OPER no router Externos

```
privilege interface level 2 description
privile configure level 2 interface
privilege exec level 2 configure terminal
privilege exec level 2 configure
```

# DNS, HTTP e SSH

* Foram criadas Named ACLs em cada um a permitir o trafego da porta 53 (DNS), 80 (HTTP) e 22 (SSH) para testar os matches e simular


# O QUE FALTA

* ACABAR A PARTE DAS FIREWALLS DO RELATORIO , IA NA DEEPZONE

------------------------


# Docentes o que tem

* tem operview
* tem service password-encryption
* tem o secret do enable

* tem o aaa new-model
* tem o aaa authorization exec default local

* tem o inspect utilizado na CBAC
* tem a Named e CBAC ACL no f0/0_in
* tem a Named ACL no f0/1_in
* tem a timebased ACL no f0/1_out

* tem o login on-failure e o login on-sucess
* tem o logging trap debugging na interface f0/0 para o host 192.168.200.2

* tem o banner exec e o  motd
* tem telnet e ssh


# Externos o que tem

* tem o privilege em vez do operview para dar permissoes ao utilizador oper

* tem service password-encryption
* tem o secret do enable


* tem o aaa new-model
* tem o aaa authorization exec default local

* tem o login on-failure e o login on-sucess
* tem o logging trap debugging na interface f0/0 para o host 192.168.200.2

* tem a Refletive ACL na f0/0_in
* tem a Named ACL na f0/1_in 
* tem a Time-Based ACL f0/1_out

* tem o banner exec e o  motd
* tem telnet e ssh

# WAN o que tem

* tem o admview
* tem a operview
* tem o privilege para o gestor

* tem o aaa new-model
* tem o aaa authorization exec default local

* tem o login on-failure e o login on-sucess
* tem o login block-for 600 attempts 3 within 60
* tem o logging trap debugging na interface g1/0 para o host 192.168.200.2

* tem o nat (PAT) inside para os docentes e o outside na g2/0

* tem o banner exec e o  motd
* tem telnet e ssh


# Core-Servicos o que tem

* tem o admview
* tem a operview
* tem o privilege para o gestor

* tem o aaa new-model
* tem o aaa authorization exec default local

* tem o login on-failure e o login on-sucess
* tem o login block-for 600 attempts 3 within 60
* tem o logging trap debugging na interface f0/0 para o host 192.168.200.2

* tem o user adm
* tem o user oper
* tem o user manager
* tem o user myaccess com o autommand access-enable host timout 2 para do malorie fazer telnet para o core-servicos com o myaccess e poder pingar o DNS

* tem a Dinamica ACL na f0/1_in 

* tem o banner exec e o  motd
* tem telnet e ssh

# DeepZone o que tem

* tem o operview

* tem o aaa new-model
* tem o aaa authentication login default local group radius
* tem o aaa accounting exec default start-stop group radius

* tem o radius-server host 192.168.200.2
* tem o radius-server host 192.168.200.2 auth-port 1812 acct-port 1813 key 7 myradiuspwd

* tem o login on-failure e o login on-sucess
* tem o logging trap debugging na interface f0/1 para o host 192.168.200.2

* tem a named ACL na f0/0_in

* tem o banner exec e o  motd
* tem telnet e ssh


# DNS, HTTP e SSH o que tem

* tem o aaa new-model
* tem o login block-for 600 attempts 3 within 60

* tem a ACL named na f0/0_in

# NAT

* Fizemos NAT com PAT no Externos e no Docentes saindo com o IP da WAN
