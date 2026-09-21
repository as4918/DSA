int myAtoi(char* s)
{
    int i = 0;
    int sign = 1;
    long result = 0;

    // Skip leading spaces
    while (s[i] == ' ')
    {
        i++;
    }

    // Check sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    // Convert digits
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');

        // Positive overflow
        if (result > 2147483647 && sign == 1)
            return 2147483647;

        // Negative overflow
        if (result > 2147483648L && sign == -1)
            return -2147483648L;

        i++;
    }

    return (int)(result * sign);
}