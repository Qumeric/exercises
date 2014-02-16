int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    // Exercise 1-16 fix
    if (i == lim-1) 
        for (; (c=getchar())!=EOF && c!='\n'; i++)
            ;
    return i;
}
