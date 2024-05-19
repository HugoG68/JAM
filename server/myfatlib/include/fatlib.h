/*
** EPITECH PROJECT, 2023
** myunilib
** File description:
** unilib
*/

#ifndef UNILIB_H_
    #define UNILIB_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define XOR(a, b) ((!a || !b) && (a || b))
    #define POS_MOD(x, m) (((x) >= 0) ? ((x) % m) : (((x) % m) + m))
    #define DIGIT_TO_CHAR(d) (d + '0')
    #define CHAR_TO_DIGIT(c) (c - '0')
    #define IS_NEG(nbr) (nbr < 0)
    #define IS_NB(c) (c >= '0' && c <= '9')
    #define IS_SPACE(c) (c == ' ' || c == '\t')

typedef enum {
    ERROR = 84,
    SUCCES = 0
} status;

status write_char(int fd, char c);
status write_number(int fd, int nbr);
status write_ln_nbr(int fd, int nbr);
status write_str(int fd, char const *str);
status write_ln(int fd, char const *str);

status my_strlen(char const *str, size_t *len_pointer);
status arr_len(void const **arr, size_t *pointer_count);

status add_str(char const *str1, char const *str2, char **pointer_str);
status add_strs(char const **list, char **pointer_str);

status my_strdup(char const *str, char **pointer_str);
status dup_arr(char **arr, char ***pointer_list);
status push(void ***list_pointer, void *new_elem);

void free_arr(void **arr);

status my_get_nbr(char const *str, int *nbr_address, bool can_be_neg);

bool same_str(char const *str_a, char const *str_b);
bool same_end(char const *str, char const *end);
bool contain(char c, char const *what);
bool str_contain(char const *str, char const *what, bool only);

status my_str_separated(char *buff, char const *exclude, char ***list_pointer);
#endif /* !UNILIB_H_ */
