	char str[90];
	//gets(str);	
    int i=0;
    fgets(str, 90, stdin);
    while (str[i] != '\n')
        i++;
    str[i] = '\0';