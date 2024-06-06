# Alumno = Miguel Molinero Martín

library(tuneR)
library(seewave)

# Lo primero, leemos los archivos wav que hemos creado antes
nombre <- readWave("nombre.wav")
apellidos <- readWave("apellidos.wav")

# Dibujamos las ondas
par(mfrow=c(2,1))
plot(nombre, main="Forma de onda del Nombre")
plot(apellidos, main="Forma de onda del Apellidos")

# Información de cabeceras
str(nombre)
str(apellidos)

# Unión de los archivos en uno
nombreyapellidos <- pastew(nombre, apellidos, output = "Wave")

# Dibujamos la forma de onda de los archivos combinados
plot(nombreyapellidos, main="Forma de onda de los archivos combinados")

# Filtro de frecuencia para eliminar frecuencias entre 10000 y 20000 Hz
frecuencias_muestreo <- nombreyapellidos@samp.rate
from_normalizado <- 10000 / (frecuencias_muestreo / 2)
to_normalizado <- 20000 / (frecuencias_muestreo / 2)
sonidofiltrado <- bwfilter(nombreyapellidos, from = from_normalizado, to = to_normalizado, bandpass = FALSE, f = frecuencias_muestreo, output = "Wave")

# Redondear los datos de los canales a enteros
sonidofiltrado@left <- round(sonidofiltrado@left)
if (!is.null(sonidofiltrado@right)) {
  sonidofiltrado@right <- round(sonidofiltrado@right)
}

# Almacenar el resultado como mezcla.wav
writeWave(sonidofiltrado, "mezcla.wav")

# Crear un nuevo sonido con eco y darle la vuelta al sonido
refran <- readWave("refran.wav")
refran_con_eco <- echo(refran, f = refran@samp.rate, amp = c(0.8, 0.4, 0.2), delay = c(0.2, 0.4, 0.6), output = "Wave")

# Darle la vuelta al sonido
refran_al_reves_matrix <- revw(refran_con_eco)
refran_al_reves <- Wave(refran_al_reves_matrix, samp.rate = refran@samp.rate, bit = refran@bit)

# Redondear los datos de los canales a enteros
refran_al_reves@left <- round(refran_al_reves@left)
if (!is.null(refran_al_reves@right)) {
  refran_al_reves@right <- round(refran_al_reves@right)
}

# Almacenar el resultado
writeWave(refran_al_reves, "alreves.wav")

