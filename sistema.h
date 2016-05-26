#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include "tipos.h"
#include "campo.h"
#include "drone.h"

class Sistema {

  public:
		Sistema();
		Sistema(const Campo &c, const Secuencia<Drone> &ds);

		const Campo& campo() const;
		EstadoCultivo estadoDelCultivo(const Posicion& p) const;
		const Secuencia<Drone>&	enjambreDrones() const;

		void crecer();
		void seVinoLaMaleza(const Secuencia<Posicion>& ps);
		void seExpandePlaga();
		void despegar(const Drone& d);
		bool listoParaCosechar() const;
		void aterrizarYCargarBaterias(Carga b);
		void fertilizarPorFilas();
		void volarYSensar(const Drone& d);

		void mostrar(std::ostream& os) const;
		void guardar(std::ostream& os) const;
		void cargar (std::istream& is);

		bool operator==(const Sistema& otroSistema) const;

	private:
        Campo _campo;
		Secuencia<Drone> _enjambre;
        Grilla<EstadoCultivo> _estado;


        //Auxiliares
        Secuencia<Posicion> parcelasDeCultivo() const;
        bool NoHayConstruccion(Posicion p);
        bool posicionLibre(Posicion p);
        Secuencia<Posicion> lugaresAdyacentes(Posicion p);
        bool HayDrone(Secuencia<Posicion> P);
        Posicion DondeEstaElGranero(Campo c);

        int cantCultivosCosechables() const;
        bool buscarPosicion(const Secuencia<Posicion> ps, const Posicion p) const;

        bool noHayDrone(Posicion p); //falta definirla!
        bool buscarDrone(Drone d); //falta definirla!
        int primerLugarCon(Secuencia<Producto> ps, Producto p);
};

//void cargarLaBateria(Sistema s , const Drone d);

// Definirlo usando mostrar, para poder usar << con este tipo.
std::ostream & operator<<(std::ostream & os,const Sistema & s);

#endif // SISTEMA_H_INCLUDED
