#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct
{
	char nombreDeUsuario[51];
	char password[51];
	int idUsuario;
	int flagDeEstado;
}EUsuario;

#endif // USUARIO_H_INCLUDED

int usu_buscaNombreUsuarioRepetido(EUsuario* arrayUsuarios, int len, char* nombreDeUsuario);
int usu_pideId(EUsuario* arrayUsuarios,int len);
int usu_bajarUsuario(EUsuario* arrayUsuarios,int len);
int usu_buscarIndiceUsuarioLibre (EUsuario* arrayUsuarios, int longitud);
int usu_initUsuario(EUsuario* arrayUsuarios, int longitud);
int usu_cargarUsuario(EUsuario* arrayUsuarios, int index, int len);
int usu_editarUsuario(EUsuario* arrayUsuarios,int len);
