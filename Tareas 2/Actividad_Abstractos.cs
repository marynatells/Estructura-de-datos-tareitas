public class Persona
{
    private string nombre;
    private int edad;
    private string direccion;

    public Persona(string nombre, int edad, string direccion)
    {
        this.nombre = nombre;
        this.edad = edad;
        this.direccion = direccion;
    }

    // Propiedades
    public string Nombre { get { return nombre; } set { nombre = value; } }
    public int Edad { get { return edad; } set { edad = value; } }
    public string Direccion { get { return direccion; } set { direccion = value; } }
}