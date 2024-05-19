# MyFTP

## Commands:

- [x] USER \<SP> \<username> \<CRLF>   : Specify user for authentication
- [x] PASS \<SP> \<password> \<CRLF>   : Specify password for authentication

- [x] CWD  \<SP> \<pathname> \<CRLF>   : Change working directory
- [x] CDUP \<CRLF>                   : Change working directory to parent directory

- [x] QUIT \<CRLF>                   : Disconnection

- [x] DELE \<SP> \<pathname> \<CRLF>   : Delete file on the server

- [x] PWD  \<CRLF>                   : Print working directory

- [ ] PASV \<CRLF>                   : Enable "passive" mode for data transfer

- [ ] PORT \<SP> \<host-port> \<CRLF>  : Enable "active" mode for data transfer


- [x] HELP [\<SP> \<string>] \<CRLF>   : List available commands

- [x] NOOP \<CRLF>                   : Do nothing
    (the following are commands using data transfer )

- [ ] RETR \<SP> \<pathname> \<CRLF>   : Download file from server to client
- [ ] STOR \<SP> \<pathname> \<CRLF>   : Upload file from client to server
- [ ] LIST [\<SP> \<pathname>] \<CRLF> : List files in the current working directory 

## USAGE:

```sh
make all
```
```sh
./myftp -h
```
