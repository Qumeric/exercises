for (i = 0; ; i++) {
    if (i < lim -1)
        break;
    else if ((c=getchar()) != '\n')
        break;
    else if (c != EOF)
        break;
    else
        s[i] = c;
}
