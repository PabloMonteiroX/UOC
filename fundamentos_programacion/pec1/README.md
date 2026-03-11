# PEC1 – Energía Cinética

## Enunciado

Implementar un programa en C que calcule la **Energía Cinética (Ec)** de un objeto en movimiento, aplicando la fórmula:

```
Ec = ½ · masa · velocidad²
```

---

## Análisis del código (`main.c`)

### Cabecera y directivas

```c
#include <stdio.h>
#define HALF 0.5F
```

- `#include <stdio.h>` incorpora las funciones estándar de entrada/salida (`printf`, `scanf`).
- `#define HALF 0.5F` define la constante simbólica `HALF` con valor `0.5` en punto flotante (`F`), evitando el uso de un número mágico directo en la fórmula.

### Variables

```c
float mass     = 0.0;
float velocity = 0.0;
float energy   = 0.0;
```

| Variable   | Tipo    | Propósito                                      |
|------------|---------|------------------------------------------------|
| `mass`     | `float` | Almacena la masa del objeto en kg              |
| `velocity` | `float` | Almacena la velocidad del objeto en m/s        |
| `energy`   | `float` | Almacena el resultado de la energía cinética   |

Se usan `float` (precisión simple) porque el enunciado no requiere alta precisión decimal.

### Entrada de datos

```c
printf("MASS?\n");
scanf("%f", &mass);

printf("VELOCITY?\n");
scanf("%f", &velocity);
```

- `scanf("%f", &var)` lee un número en punto flotante desde la entrada estándar y lo almacena en la dirección de `var` (operador `&`).

### Cálculo

```c
energy = HALF * mass * velocity * velocity;
```

Aplica la fórmula `Ec = ½ · m · v²`.  
Se expresa `v²` como `velocity * velocity` en lugar de `pow(velocity, 2)` para evitar dependencias de `<math.h>` y mantener la solución simple.

### Salida de datos

```c
printf("KINETIC ENERGY: %.2f\n", energy);
```

El especificador `%.2f` formatea el resultado con exactamente dos decimales, tal como requiere el enunciado.

---

## Ejemplo de ejecución

```
INPUT
MASS?
75.5
VELOCITY?
12.2
OUTPUT
KINETIC ENERGY: 5618.71
```

---

## Compilación y ejecución

```bash
gcc -Wall -Wextra -o pec1 main.c
./pec1
```
