/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
    #include "../myfatlib/include/fatlib.h"
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <limits.h>
    #include <stdio.h>

    #define USERNAME_DEFAULT "Anonymous"
    #define PASSWORD_DEFAULT ""
    #define CRLF "\r\n"

    #define SERVIC_NOT_READY_YET "120"
    #define OPEN_OR_DATA_TRANSFER "125"
    #define FILE_OK_DATA_CONNETION "150"
    #define STATUS_OK "200"
    #define HELP_RESP "214"
    #define SERVICE_READY "220"
    #define LOG_OUT "221"
    #define CLOSING_DATA_CONNEXION "226"
    #define PASSIVE_MODE "227"
    #define LOGGED_IN "230"
    #define FILE_REQUSET_OK "250"
    #define FILE_CREATED "257"
    #define USER_OK_WHERE_PASS "331"
    #define NOT_LOGGED "332"

    #define ERR_USR_PASS "430"
    #define SYNTAX_ERROR "550"
    #define ERR_SEQUENCE "503"

enum command_list_index {
    IDX_USER,
    IDX_PASS,

    IDX_CWD,
    IDX_CDUP,

    IDX_QUIT,
    IDX_DELE,
    IDX_PWD,
    IDX_PASV,
    IDX_PORT,

    IDX_HELP,
    IDX_NOOP,

    IDX_RETR,
    IDX_STOR,
    IDX_LIST,

    IDX_MAX,
};

typedef enum connection_status_s {
    DISCONNECTED,
    WAIT_PASS,
    LOGGED
} connection_status_t;

typedef struct client_s {
    char *pwd;
    int socket;
    struct client_s *next;
    struct client_s *prev;
    connection_status_t is_connected;
} client_t;

typedef struct command_s {
    char *name;
    size_t arg_nb;
    void (*func)(struct command_s *this, client_t *client, char **command);
} command_t;

typedef struct rank_s {
    char *name;
    size_t score;
    size_t index;
    struct rank_s *next;
} rank_t;

typedef struct ftp_s {
    socklen_t len;
    fd_set reads;
    struct timeval timeout;
    int main_socket;
    struct sockaddr_in *in;
    struct sockaddr client_address;
    int user_count;
    client_t *client;
    char const *path;
    command_t *commands;
    rank_t *rank;
}ftp_t;


void check_print_help(char const *arg);
ftp_t *construct_ftp(char const *path);
ftp_t *open_server(int port, char const *path);
void destroy_ftp(ftp_t *my_ftp);
void main_node(ftp_t *my_ftp);
int handle_fds(int len_fds, ftp_t *my_ftp);
void read_fds(ftp_t *my_ftp);

void read_user(client_t *client, rank_t **list);
void clear_user(client_t **client);

void append_client(char const *path, int socket, client_t **client_list_p);
void destroy_client(client_t *client, client_t **head_p);

command_t *make_command_list(void);

void write_user(int fd, char const *str);
bool is_not_logged(client_t *client);

void user(struct command_s *this, client_t *client, char **command);
void pass(struct command_s *this, client_t *client, char **command);
void quit(struct command_s *this, client_t *client, char **command);
void noop(struct command_s *this, client_t *client, char **command);
void help(struct command_s *this, client_t *client, char **command);
void pwd(struct command_s *this, client_t *client, char **command);
void cwd(struct command_s *this, client_t *client, char **command);
void cdup(struct command_s *this, client_t *client, char **command);
void dele(struct command_s *this, client_t *client, char **command);

#endif /* !MYFTP_H_ */
