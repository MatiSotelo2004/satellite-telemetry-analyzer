# 🛰️ Trabajo Práctico - Tópicos de Programación
## Análisis de Datos de Telemetría Satelital

### 📋 Descripción del Proyecto

Este proyecto consiste en el desarrollo de una solución para procesar y analizar datos de telemetría satelital. El objetivo principal es obtener valores medios de voltaje aislados y generar gráficos a partir de archivos binarios que contienen información de sensores satelitales.

### 🎯 Objetivos

- Procesar archivos binarios de telemetría satelital
- Extraer y analizar datos de voltaje de sensores
- Generar visualizaciones gráficas de los datos procesados
- Implementar soluciones compatibles con diferentes arquitecturas de hardware

### 📊 Especificaciones Técnicas

#### Parte 1: Procesamiento de Archivos Binarios

**Archivo de entrada:** `HKTMT.bin` (aprox. 4000 bytes)
- Contiene captura de datos de telemetría satelital
- Estructura de registros/paquetes de 4000 bytes cada uno
- Información de posición en bytes para volcado de datos
- Tabla de comandos CDH (Command and Data Handling)

**Características del archivo:**
- Registros con cantidad desconocida de paquetes
- Control de cantidad de bytes (divisible por 4000)
- Información de tiempo (OBT - On Board Time)
- Datos de telemetría en formato crudo

#### Parte 2: Análisis de Voltaje

**Procesamiento de datos:**
- Valores de voltaje en formato "crudo/raw" (enteros)
- Conversión mediante cálculos específicos del sensor
- Valores objetivo: aproximadamente 33v con variaciones entre 31.5v y 32v
- Detección de períodos de eclipse solar
- Identificación de paneles que no pueden cargar durante eclipses

**Especificaciones de hardware:**
- Compatible con sistemas Intel/AMD
- Soporte para diferentes tipos de encoding
- Implementación de soluciones para arquitecturas big-endian y little-endian

### 📈 Resultados Esperados

1. **Gráfico de voltaje vs tiempo** mostrando:
   - Variaciones de voltaje a lo largo del tiempo
   - Identificación clara de períodos de eclipse
   - Valores entre 31.5v y 32v aproximadamente

2. **Análisis de datos CDH:**
   - Procesamiento de timestamps (OBT)
   - Extracción de información de cada paquete
   - Correlación entre tiempo y mediciones
  
**Universidad Nacional de La Matanza (UNLaM)**  
**Materia:** Tópicos de Programación  
**Año:** 2023
