#ifndef RELACIONSOCIOSERVICIO_H_INCLUDED
#define RELACIONSOCIOSERVICIO_H_INCLUDED

typedef struct
{
    int idSocio;
    int idServicio;
    int idSocioServicio;
    int estado;
}SocioServicio;
#endif // RELACIONSOCIOSERVICIO_H_INCLUDED
#define SOCIOS_SERVICIOS_ESTADO_INACTIVO 1
#define SOCIOS_SERVICIOS_ESTADO_ACTIVO 0

SocioServicio* socserv_new(int idSocio, int idServicio, int idSocioServicio, int estado);
int socserv_setIdSocioServicio(SocioServicio* this,int idSocioServicio);
int socserv_getIdSocioServicio(SocioServicio* this);
int socserv_setIdServicio(SocioServicio* this,int idServicio);
int socserv_getIdServicio(SocioServicio* this);
int socserv_setIdSocio(SocioServicio* this,int idSocio);
int socserv_getIdSocio(SocioServicio* this);
int socserv_setEstado(SocioServicio* this,int estado);
int socserv_getEstado(SocioServicio* this);
SocioServicio* socserv_findById(ArrayList* pArraySocioServicio, int idSocioServicio);
SocioServicio* socserv_findByIds(ArrayList* pArraySocioServicio, int idSocio, int idServicio);
