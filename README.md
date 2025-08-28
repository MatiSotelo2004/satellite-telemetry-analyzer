# 🛰️ Trabajo Práctico - Tópicos de Programación
## Análisis de Datos de Telemetría Satelital

### 📋 Descripción del proyecto

Este proyecto consiste en el desarrollo de una solución para procesar y analizar datos de telemetría satelital. El objetivo principal es obtener valores medios de voltaje aislados y generar gráficos a partir de archivos binarios que contienen información de sensores satelitales.

### 🎯 Objetivos

- Procesar archivos binarios de telemetría satelital
- Extraer y analizar datos de voltaje de sensores
- Generar visualizaciones gráficas de los datos procesados
- Implementar soluciones compatibles con diferentes arquitecturas de hardware

### 📊 Especificaciones Técnicas

#### Procesamiento de Archivos Binarios

**Archivo de entrada:** `HKTMT.bin`
- Contiene captura de datos de telemetría satelital
- Estructura de registros/paquetes de 4000 bytes cada uno
- Información de posición en bytes para volcado de datos

**Características del archivo:**
- Registros con cantidad desconocida de paquetes
- Control de cantidad de bytes (divisible por 4000)
- Información de tiempo (OBT - On Board Time)
- Datos de telemetría en formato crudo

#### Análisis de Voltaje

**Procesamiento de datos:**
- Valores de voltaje en formato "crudo/raw" (enteros)
- Conversión mediante cálculos específicos del sensor
- Valores objetivo: aproximadamente 33v con variaciones entre 31.5v y 32v
- Identificación de paneles que no pueden cargar durante eclipses

**Especificaciones de hardware:**
- Compatible con sistemas Intel/AMD
- Soporte para diferentes tipos de encoding
- Implementación de soluciones para arquitecturas big-endian y little-endian

### 📈 Resultados Esperados

1. **Gráfico de voltaje vs tiempo** mostrando:
   - Variaciones de voltaje a lo largo del tiempo
   - Valores entre 31.5v y 32v aproximadamente

2. **Análisis de datos CDH:**
   - Procesamiento de timestamps (OBT)
   - Extracción de información de cada paquete
   - Correlación entre tiempo y mediciones

### 🛠️ Resolución y Explicación del Código

El procesamiento de los datos binarios se realiza en C, considerando la arquitectura del sistema (big-endian o little-endian) para asegurar la correcta interpretación de los valores crudos. Algunas funciones clave implementadas son:

- **`es_little_endian()`**: Determina el tipo de arquitectura del sistema para adaptar la lectura de los datos binarios.
- **`invertir_2bytes()` y `invertir_4bytes()`**: Permiten convertir valores entre big-endian y little-endian, asegurando la compatibilidad con diferentes plataformas.
- **`obtener_PCS()`**: Convierte el valor crudo del voltaje leído desde el archivo binario al formato físico requerido, aplicando la conversión necesaria según el sensor.
- **`obtener_CDH()`**: Extrae y convierte la marca de tiempo (OBT) de cada paquete, permitiendo correlacionar los datos de voltaje con el tiempo.


  
**Universidad Nacional de La Matanza (UNLaM)**  
**Materia:** Tópicos de Programación  
**Año:** 2023
