# PEC2 – Sistema de Riego Inteligente

## Enunciado

Implementar un programa en C que determine si el **sistema de riego** de una parcela debe activarse, en función de la humedad del suelo, el tipo de planta y la temperatura exterior. **No se permite el uso de condicionales (`if`/`else`).**

---

## Análisis del código (`main.c`)

### Cabecera y directivas

```c
#include <stdio.h>
#include <stdbool.h>
```

- `<stdio.h>` proporciona `printf` y `scanf`.
- `<stdbool.h>` habilita el tipo `bool` y los literales `true` / `false`, mejorando la legibilidad respecto a usar `int`.

### Constantes simbólicas

```c
#define EMERGENCY_HUMIDITY  10
#define SUCCULENT_HUMIDITY  20
#define SHRUB_HUMIDITY      40
#define TROPICAL_HUMIDITY   60
#define HEAT_TEMPERATURE    35
#define HEAT_HUMIDITY       50
#define SUCCULENT            0
#define SHRUB                1
#define TROPICAL             2
```

Cada umbral numérico se sustituye por una constante con nombre descriptivo, lo que cumple el requisito de evitar números mágicos y facilita el mantenimiento.

### Variables

```c
float  humidity    = 0.0;
int    plantType   = 0;
float  temperature = 0.0;
bool   activate    = false;
```

| Variable      | Tipo    | Propósito                                                 |
|---------------|---------|-----------------------------------------------------------|
| `humidity`    | `float` | Nivel de humedad del suelo (0–100 %)                      |
| `plantType`   | `int`   | Tipo de planta (0 = suculenta, 1 = arbusto, 2 = tropical) |
| `temperature` | `float` | Temperatura exterior en grados Celsius                    |
| `activate`    | `bool`  | Resultado: `true` si se debe activar el riego             |

### Entrada de datos

```c
printf("HUMIDITY PERCENTAGE?\n");
scanf("%f", &humidity);

printf("PLANT TYPE (0-SUCCULENT, 1-SHRUB, 2-TROPICAL)?\n");
scanf("%d", &plantType);

printf("OUTDOOR TEMPERATURE?\n");
scanf("%f", &temperature);
```

- `%f` lee `float`; `%d` lee `int`.

### Lógica de activación (expresión booleana)

```c
activate =
    (humidity < EMERGENCY_HUMIDITY)                              ||
    (plantType == SUCCULENT && humidity < SUCCULENT_HUMIDITY)    ||
    (plantType == SHRUB     && humidity < SHRUB_HUMIDITY)        ||
    (plantType == TROPICAL  && humidity < TROPICAL_HUMIDITY)     ||
    (temperature > HEAT_TEMPERATURE && humidity < HEAT_HUMIDITY);
```

Se usa una **única expresión booleana** con operadores `||` (OR) y `&&` (AND) para respetar la restricción de no usar condicionales. Cada condición se corresponde con un criterio del enunciado:

| Condición                                                | Criterio                                      |
|----------------------------------------------------------|-----------------------------------------------|
| `humidity < EMERGENCY_HUMIDITY`                          | Riego de emergencia (< 10 %)                  |
| `plantType == SUCCULENT && humidity < SUCCULENT_HUMIDITY`| Suculenta y humedad < 20 %                    |
| `plantType == SHRUB && humidity < SHRUB_HUMIDITY`        | Arbusto y humedad < 40 %                      |
| `plantType == TROPICAL && humidity < TROPICAL_HUMIDITY`  | Tropical y humedad < 60 %                     |
| `temperature > HEAT_TEMPERATURE && humidity < HEAT_HUMIDITY` | Calor (> 35 °C) y humedad < 50 %         |

La evaluación **en cortocircuito** de C garantiza eficiencia: si una condición es `true`, las siguientes no se evalúan.

### Salida de datos

```c
printf("ACTIVATING IRRIGATION (0-FALSE, 1-TRUE): %d\n", activate);
```

`%d` imprime el valor entero de `activate` (`0` = false, `1` = true), tal como indica el formato del enunciado.

---

## Tabla de verdad simplificada

| Humedad | Tipo planta  | Temperatura | ¿Riego? | Motivo                        |
|---------|--------------|-------------|---------|-------------------------------|
| 5 %     | cualquiera   | cualquiera  | Sí      | Emergencia (< 10 %)           |
| 15 %    | Suculenta    | 20 °C       | Sí      | Umbral suculenta (< 20 %)     |
| 15 %    | Arbusto      | 20 °C       | No      | Arbusto requiere < 40 %       |
| 35 %    | Arbusto      | 20 °C       | Sí      | Umbral arbusto (< 40 %)       |
| 55 %    | Tropical     | 20 °C       | Sí      | Umbral tropical (< 60 %)      |
| 45 %    | Suculenta    | 38 °C       | Sí      | Calor preventivo (> 35 °C, < 50 %) |
| 70 %    | cualquiera   | 20 °C       | No      | Ningún criterio se cumple     |

---

## Ejemplo de ejecución

```
INPUT
HUMIDITY PERCENTAGE?
5.0
PLANT TYPE (0-SUCCULENT, 1-SHRUB, 2-TROPICAL)?
0
OUTDOOR TEMPERATURE?
25.0
OUTPUT
ACTIVATING IRRIGATION (0-FALSE, 1-TRUE): 1
```

---

## Compilación y ejecución

```bash
gcc -Wall -Wextra -o pec2 main.c
./pec2
```
