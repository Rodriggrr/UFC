namespace math
{

    // Return MAX value
    template <typename T>
    T max(T a, T b)
    {
        return (a > b) ? a : b;
    }

    // Return MIN value
    template <typename T>
    T min(T a, T b)
    {
        return (a < b) ? a : b;
    }

    // Return ABS value
    template <typename T>
    T abs(T a)
    {
        return (a < 0) ? -a : a;
    }

    // Return the factorial of a number
    template <typename T>
    T factor(T a)
    {
        T result = 1;
        for (T i = 1; i <= a; i++)
            result *= i;
        return result;
    }

    // Return the power of a number
    template <typename T>
    T pow(T a, int b)
    {
        T result = 1;
        for (T i = 0; i < b; i++)
            result *= a;
        return result;
    }

    // Return the square root of a number
    template <typename T>
    float sqrt(T a)
    {
        float result = 1;
        for (T i = 1; i < a; i++)
        {
            if (i * i == a)
                return i;
            else if (i * i > a)
            {
                result = i - 1;
                break;
            }
        }
        for (float i = 0.1; i < 1; i += 0.1)
            if (pow(result + i, 2) > a)
                return result + i - 0.1;

        return result;
    }
}