#include <stdio.h> // Para el printf original y NULL
#include <limits.h> // Para INT_MAX, INT_MIN, UINT_MAX
#include "ft_printf.h" // ¡Asegúrate de que esta sea la ruta correcta a tu ft_printf.h!

int main(void)
{
    int my_chars;
    int original_chars;

    printf("--- INICIANDO PRUEBAS DE FT_PRINTF VS. PRINTF ORIGINAL ---\n\n");

    // --- PRUEBAS DE %c (carácter) ---
    printf("--- PRUEBAS DE %%c ---\n");
    my_chars = ft_printf("ft_printf Mi caracter es: %c\n", 'A');
    original_chars = printf("Original: Mi caracter es: %c\n", 'A');
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Otro caracter: %c\n", '!');
    original_chars = printf("Original: Otro caracter: %c\n", '!');
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Caracter nulo: %c (debería imprimir nada)\n", '\0');
    original_chars = printf("Original: Caracter nulo: %c (debería imprimir nada)\n", '\0');
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars); // Cuidado: printf podría no contar '\0' si no se imprime


    // --- PRUEBAS DE %s (cadena) ---
    printf("--- PRUEBAS DE %%s ---\n");
    my_chars = ft_printf("ft_printf Mi cadena es: %s\n", "Hola Mundo!");
    original_chars = printf("Original: Mi cadena es: %s\n", "Hola Mundo!");
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Cadena vacía: %s\n", "");
    original_chars = printf("Original: Cadena vacía: %s\n", "");
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Cadena NULL: %s\n", (char *)NULL); // Debería imprimir "(null)"
    original_chars = printf("Original: Cadena NULL: %s\n", (char *)NULL);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    // --- PRUEBAS DE %p (puntero) ---
    printf("--- PRUEBAS DE %%p ---\n");
    int my_int_var = 123;
    char *my_str_var = "testing";
    void *null_ptr = NULL;

    my_chars = ft_printf("ft_printf Dirección de int: %p\n", &my_int_var);
    original_chars = printf("Original: Dirección de int: %p\n", &my_int_var);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Dirección de string: %p\n", my_str_var);
    original_chars = printf("Original: Dirección de string: %p\n", my_str_var);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Puntero NULL: %p\n", null_ptr); // Debería imprimir 0x0
    original_chars = printf("Original: Puntero NULL: %p\n", null_ptr);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Dirección de main: %p\n", &main);
    original_chars = printf("Original: Dirección de main: %p\n", &main);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    // --- PRUEBAS DE %d y %i (entero decimal) ---
    printf("--- PRUEBAS DE %%d y %%i ---\n");
    my_chars = ft_printf("ft_printf Número positivo: %d\n", 42);
    original_chars = printf("Original: Número positivo: %d\n", 42);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Número negativo: %i\n", -12345);
    original_chars = printf("Original: Número negativo: %i\n", -12345);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Cero: %d\n", 0);
    original_chars = printf("Original: Cero: %d\n", 0);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf INT_MAX: %d\n", INT_MAX);
    original_chars = printf("Original: INT_MAX: %d\n", INT_MAX);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf INT_MIN: %d\n", INT_MIN);
    original_chars = printf("Original: INT_MIN: %d\n", INT_MIN);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    // --- PRUEBAS DE %u (entero sin signo) ---
    printf("--- PRUEBAS DE %%u ---\n");
    my_chars = ft_printf("ft_printf Unsigned positivo: %u\n", 42U);
    original_chars = printf("Original: Unsigned positivo: %u\n", 42U);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Unsigned cero: %u\n", 0U);
    original_chars = printf("Original: Unsigned cero: %u\n", 0U);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf UINT_MAX: %u\n", UINT_MAX);
    original_chars = printf("Original: UINT_MAX: %u\n", UINT_MAX);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Unsigned de int negativo (-1): %u\n", (unsigned int)-1); // Esto es UINT_MAX
    original_chars = printf("Original: Unsigned de int negativo (-1): %u\n", (unsigned int)-1);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Unsigned de int negativo (-42): %u\n", (unsigned int)-42);
    original_chars = printf("Original: Unsigned de int negativo (-42): %u\n", (unsigned int)-42);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);


    // --- PRUEBAS DE %x y %X (hexadecimal) ---
    printf("--- PRUEBAS DE %%x y %%X ---\n");
    my_chars = ft_printf("ft_printf Hex min (0): %x\n", 0);
    original_chars = printf("Original: Hex min (0): %x\n", 0);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Hex min (10): %x\n", 10); // a
    original_chars = printf("Original: Hex min (10): %x\n", 10);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Hex may (255): %X\n", 255); // FF
    original_chars = printf("Original: Hex may (255): %X\n", 255);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Hex min (42): %x\n", 42); // 2a
    original_chars = printf("Original: Hex min (42): %x\n", 42);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Hex may (0xABCDEF): %X\n", 0xABCDEF); // ABCDEF
    original_chars = printf("Original: Hex may (0xABCDEF): %X\n", 0xABCDEF);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Hex min (UINT_MAX): %x\n", UINT_MAX); // ffffffff
    original_chars = printf("Original: Hex min (UINT_MAX): %x\n", UINT_MAX);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    // --- PRUEBAS DE %% (porcentaje literal) ---
    printf("--- PRUEBAS DE %%%% ---\n");
    my_chars = ft_printf("ft_printf Esto es un porcentaje literal: %%\n");
    original_chars = printf("Original: Esto es un porcentaje literal: %%\n");
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    my_chars = ft_printf("ft_printf Dos porcentajes: %%%%.\n");
    original_chars = printf("Original: Dos porcentajes: %%%%.\n");
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);


    printf("--- PRUEBAS ADICIONALES (combinaciones) ---\n");
    my_chars = ft_printf("ft_printf Caracter: %c, String: %s, Entero: %d, Unsigned: %u, Hex: %x, Ptr: %p\n",
                           'Z', "Combinado", -500, 1000U, 255, (void*)&my_int_var);
    original_chars = printf("Original: Caracter: %c, String: %s, Entero: %d, Unsigned: %u, Hex: %x, Ptr: %p\n",
                           'Z', "Combinado", -500, 1000U, 255, (void*)&my_int_var);
    printf("ft_printf chars: %d, Original chars: %d\n\n", my_chars, original_chars);

    printf("--- FIN DE LAS PRUEBAS ---\n");

    return (0);
}
