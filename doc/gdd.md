# Game Design Document

# NaZury

## Sheet 1

**Título del juego** :

Se ha realizado una reunión brainstorming y salieron las opciones que mostramos a continuación:

- DreamBoy
- Neverland
- Under ur bed
- Sweet dreams
- Mario´s Nightmare
- **Not a Nightmare**
- Where am I?
- Escape Dream

Finalmente decidimos que el nombre definitivo para nuestro juego sería **&quot;Not a nightmare&quot;.**

**Sistema de juego** :

Nuestra idea es un juego en el que predominan los puzzles y el sigilo, con tipo de vista cenital. No hay sistema de combate, por lo que tampoco se usarán armas. Lo que sí habrá son objetos utilizables para diversas funciones, dependiendo del nivel y su objetivo.

A la hora de enfrentarse a los adversarios, al no usar armas, habrá que mantener el sigilo y evitarlos a toda costa, encontrando los objetos necesarios para escapar de la sala.

**Público al que va dirigido** :

Se ha sopesado la probabilidad de categorizar nuestro juego con PEGI 7 ya que tenemos pensado caracterizar nuestro juego con una temática oscura sin mostrar violencia específica. Sin embargo hemos decidido finalmente denominarlo con PEGI 12 por el trasfondo que queremos mostrar

PEGI +12

**Resumen de la historia del juego orientada a la jugabilidad** :

Viaje del personaje superando sus inseguridades o miedos.

El personaje empieza en una habitación de bebé (medio tétrica) con juguetes, cunas, etc. No sabe cómo ha llegado hasta allí ni por qué, sin embargo, sabe que tiene que salir de esa habitación como sea, para salir de ahí necesita descifrar una serie de obstáculos y puzzles a la vez que huye de sus miedos. A medida que el personaje avanza en el juego, se va dando cuenta de lo que sucede a su alrededor y va entendiendo de que se encuentra en una especie de sueño/pesadilla, en la que en cada nivel se ven reflejados sus miedos e inseguridades de manera que el viaje a través del juego es una representación de la evolución del protagonista y su maduración superando del mismo modo sus miedos e inseguridades más profundos.

**Distintos modos de juego** :

- Sweet Dream (modo normal)
- Nightmare

**Puntos únicos de nuestro juego** : (cinco minimo que destacan a nuestro juego)

- Investigación
- Sigilo
- Puzzle
- Misterio
- Temática Visual Dinámica

**Juegos parecidos** :

- Little Nightmares
- Among The Sleep
- Among Us
- Limbo
- Saga Cube Escape
- Samsara Room
- My Friend Is a Raven

## Sheet 2

**Jugabilidad** :

- **Cómo se progresa en el juego** :

Superando los niveles de cada sala

- **Misiones y estructura de retos** :

1.Comienza gateando/bebe -\&gt; puzzle tetris

2.Payaso/sombra/circo/niño -\&gt; puzzle Gusanillo

3.Colegio/matón/director/bocadillo -\&gt; Rebotes

## Futuros niveles

4.Callejón oscuro/ ladrones -\&gt; ladrones buscando al jugador (zonas de visión)

5.Universidad/exámenes -\&gt; exámenes con acertijos (opcional) (posibles preguntas. Examen de IQ, o preguntas estilo entrena tu mente)

6.Trabajo/jefe -\&gt; resolver juego de pareja de cartas con Joker (Jefe)

7.Pareja/perder hijo (casa-centro comercial) -\&gt; buscar hijo

8.Viejo /muerte (la misma sala) ( que nadie le visite ) (y que en la última sala la muerte)/pastillas utilizables que ralentizan la muerte.

- **Estructuras de puzzle** :

Resolver los puzzles de cada nivel.

**-**** Objetivos del juego**:

Conseguir superar a los enemigos y completar el nivel de cada sala y avanzar hasta completarlos todos y conseguir escapar.

**Cuantificación** :

**-**** Lugares en los que se desarrolla el juego**: Cuarto de bebé, circo, colegio, callejón

oscuro, universidad, trabajo, centro comercial, habitación.

**-**** Número de niveles**: 3 desarrollados -\&gt;  5 niveles mas para el futuro

**-**** Número de NPC´s**: entre 1 y 3 enemigos por nivel.

**-**** Número de armas**: No hay.

**Flujos de juego** : 

Puedes ver nuestro Diagrama en el siguiente enlace:

https://drive.google.com/file/d/1Lj7kdPJR5wbZJxWcXQrKa_C5C20EwetS/view?usp=sharing


## Sheet 3

**Sistema de juego:**

**-HUD y controles:**

- No tiene

**-Menús**

**--Menu principal**

- **Nueva partida :**
- **Opciones.**
  - **Controles.**
- **Salir.**

**--Menu de pausa**

- **Continuar la partida**
- **Opciones.**
  - **Controles.**
- **Salir.**


**-Características Motor 2D :**


**-Cámara:** La cámara que vamos a usar en nuestro juego será de tipo Top down camera.

**Controles:**

- **Movimiento:** W,A,S,D.
- **Recoger objeto:** E.
- **Interacciones:** E.
- **Movimiento de menu:** Up, Down 

**Sonido:**

- Música de fondo dependiendo de la sala.
- Sonido al recoger elemento.
- Sonido de pasos.
- Sonido de linterna.
- Sonido para puertas.
- Sonido de extras.


**Sistema de ayuda:**

En nuestro juego la idea es realizar un tutorial sencillo en el primer nivel sobre que tiene que hacer el jugador. Además , al inicio de cada nivel se hará una pequeña referencia al objetivo que se ha de cumplir en el nivel.

## Sheet 7

**IA del oponente:** Los miedos del protagonista , de manera técnica sería un NPC que le plantaría un reto al jugador.

**IA de los NPC** : Npc con recorridos, rango de visión, perseguir al jugador.

**IA de los amigos:** En un principio no habrá .

**IA de soporte** : En principio no tenemos pensado ninguna IA de soporte por el momento.

## Sheet 10

**Ejecutables:**

**Hito 1:**

- **Ventana de juego.**
- **Menú**
- **personaje direcciones**.
- **Animación personaje andando.**
- **Cargar un mapa.**
- **Colisiones.**
- Cámara que sigue al personaje principal. ( que la pantalla tenga un zoom y se mueva con el personaje )
- Enemigo que ve el personaje (ponerle un rango de visión al enemigo, si se pone delante que salga algo diciendo que lo detecta y que no lo detecte si tiene un objeto en medio)
- **Enemigo con un recorrido( un enemigo que se mueva de derecha a izquierda y en cruz)**
- **Secuencias de diálogos ( que cambie el diálogo cada vez que pulses una tecla )**
- **Cambios de sala** (al llegar al borde de una sala , cambiar a la otra)
- **Evento abrir puerta** ( una pantalla que pida el código , si el código esta bien pone correcto , si no incorrecto)
- **Buscar un elemento** ( Al ponerte encima del elemento que buscas pone &quot;Encontrado&quot;)
- pelea por turnos corta.
- Punto de guardado.
- Iluminación con movimiento (Luz de linternas) .
- Enemigo que se mueve hacia el personaje cuando no le apunta.

- minijuegos:

- piezas de madera: Coger un elemento con el ratón y arrastrarlo a otro punto.
- Simon dice: secuencia de imágenes aleatorias. y copiarlas en el otro lado ( among us)
- Pareja de cartas: 4 parejas y 2 jefes , si aparece una carta jefe pierdes)
- **Bola**

**Hito 2:**

Construir el juego juntando todas las funcionalidades.

Hacer los mapas y los niveles.

Ejecutables:

- Beta del juego

Cosas que han faltado para este hito: 

- Dialogos
- Interpolacion
- Todavia nos queda Arreglar ciertas cosas puntuales

**Hito 3:**

Montaje de los niveles del juego , realizacion de nuevo cargador de mapas, colisiones con los mapas , puzzles, ...

Ejecutables:

- Juego final.
