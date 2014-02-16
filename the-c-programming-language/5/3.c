void strcat(char *s, char *t)
{
    while(*s++)    // Find EOF
        ;
    while(*s++ = *t++) // Copy t
        ;
    *s = '\0';
}
