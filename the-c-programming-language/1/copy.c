void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
}
