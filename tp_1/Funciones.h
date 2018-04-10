/** \brief Suma dos numeros entre si
 *
 * \param primer numero a ser sumado
 * \param segundo numero a ser sumado
 * \return la suma entre los dos numeros
 *
 */
float suma(float numero1, float numero2);

/** \brief resta el segundo parametro al primero
 *
 * \param el minuendo de la resta
 * \param el substraendo de la resta
 * \return La diferencia entre los dos numeros
 *
 */
float resta(float numero1, float numero2);

/** \brief Multiplica dos numeros entre si
 *
 * \param El primer numero que sera multiplicado
 * \param El segundo numero que sera multiplicado
 * \return El resultado de la multiplicacion
 *
 */
float multiplicacion(float numero1, float numero2);

/** \brief Se divide el primer termino por el segundo
 *
 * \param el divisor de la cuenta
 * \param el dividendo de la cuenta
 * \return El resultado de la division entre los dos numeros
 *
 */
float division(float numero1, float numero2);

/** \brief Realiza el factorial del parametro entregado
 *
 * \param Numero que se va a factorial
 * \return El resultado del factorial del numero, o 0 si el factorial no se puede realizar(numeros decimales y negativos)
 *
 */
unsigned long long int factorial(float numero);
/** \brief Se chequea el estado
 *
 * \param el divisor de la cuenta
 * \param el dividendo de la cuenta
 * \return El resultado de la division entre los dos numeros
 *
 */
int Inicializados(int AInicializado,int BInicializado);
/** \brief Se fija si cada uno de los digitos de la cadena ingresada corresponden a valores numerico, y no mas de un  punto y coma
 *
 * \param La cadena a ser comprobada
 * \return Devuelve 1 si verdadero y 0 si falso
 */
int validaNumero(char *numeroIngresado);
