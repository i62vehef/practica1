## Configuración básica

### Nombre del Administrador:

`git confing --global user.name "Antonio M. Durán Rosal`

### Correo electrónico:

`git config --global user.email aduran @uco.es`

### Editor de texto:

`git config --global core.editor "gedit"`

### Color de la interfaz:

`git config --global color.ui true`

### Listado de configuración:

`git config --list`


## Los tres estados Git

![texto alternativo](https://git-scm.com/figures/18333fig0106-tn.png)

## Comandos básicos

### Iniciar repositorio en un directorio:

`git init`

### Agregar cambios al area de *staging*:

`git add`

### Validar cambios en el repositorio:

`git commit -m "Mensaje"`

### Hacer los dos cambios anteriores en uno:

`git commit -am "Mensaje"`

### Historial de commits:

`git log` 


### Comandos básicos II:

### Ayuda del listado anterior:

`git help log`

### Listar los 5 commits màs recientes:

`git log -n 5`

### Listar los commits desde una fecha:

`git log --since=2018-09-18`

### Listar los commits por autor:

`git log --author =" Antonio"`

### Ver cambios en el directorio:

`git status`

