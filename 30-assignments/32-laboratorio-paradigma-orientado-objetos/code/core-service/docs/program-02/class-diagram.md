# Diagrama de Clases - Programa 02 (Alumno)

## 1\. Código PlantUML (textuml) del Sistema

Este diagrama modela la clase `Alumno` y el "Programa" completo (con las clases `Programa`, `GestionAlumnos` y `ArchivoAlumnos`), diseñado para cumplir con todos los [requerimientos funcionales y no funcionales](04-projects/prj-tecnicatura-superior-sistemas/year/01/algoritmos-y-estructuras-de-datos-i/30-assignments/32-laboratorio-paradigma-orientado-objetos/code/core-service/docs/program-02/software-requirements-specification.md).

```plantuml
@startuml
' Configuración para un diagrama más limpio
skinparam classAttributeIconSize 0
hide empty_members

' RNF-05: Aplicar Espacios de Nombres
namespace program02 {

    ' RNF-01, RNF-03: Separación de responsabilidades (Modelo de Datos)
    class Alumno {
        - cedula: string
        - nombre: string
        - nota1: float
        - nota2: float
        - nota3: float

        + Alumno()
        + SetCedula(ced: string): void
        + GetCedula(): string
        + SetNombre(nom: string): void
        + GetNombre(): string
        + SetNota1(n1: float): void
        + GetNota1(): float
        + SetNota2(n2: float): void
        + GetNota2(): float
        + SetNota3(n3: float): void
        + GetNota3(): float
        
        ' RF-07, RF-08
        + NotaFinal(): float
        + AproRepro(): string
    }

    ' RNF-01, RNF-03: Separación (Persistencia)
    class ArchivoAlumnos {
        + guardar(alumnos: Alumno[], cantidad: int): void
        + cargar(alumnos: Alumno[]&, cantidad: int&): void
    }

    ' RNF-01, RNF-03: Separación (Lógica de Negocio)
    class GestionAlumnos {
        ' RNF-07: Se usa un array, no STL
        - alumnos: Alumno[]
        - cantidadAlumnos: int
        - archivo: ArchivoAlumnos
        
        ' RF-01, RF-02, RF-03, RF-04 (CRUD)
        + crearAlumno(ced: string, nom: string, n1: float, n2: float, n3: float): void
        + leerAlumno(id: int): Alumno
        + actualizarAlumno(id: int, ced: string, nom: string, n1: float, n2: float, n3: float): void
        + eliminarAlumno(id: int): void
        
        ' RF-05, RF-06
        + cargarDatos(): void
        + guardarDatos(): void
    }

    ' RNF-01, RNF-03: Separación (Interfaz de Usuario)
    class Programa {
        - gestion: GestionAlumnos
        
        + ejecutar(): void
        - mostrarMenu(): void
        - altaAlumno(): void
        - bajaAlumno(): void
        - modificacionAlumno(): void
        
        ' RF-09
        - listarAlumnos(): void
    }

    ' Definición de relaciones
    Programa "1" *-- "1" GestionAlumnos : utiliza >
    GestionAlumnos "1" *-- "1" ArchivoAlumnos : gestiona >
    
    ' RNF-07: Gestion contiene "N" Alumnos (array)
    GestionAlumnos "1" o-- "N" Alumno : contiene >
}

@enduml
```

-----

## 2\. Diagrama de Clases (PlantUml)

[![](https://img.plantuml.biz/plantuml/svg/hLRDJjj04BxxAKOvKASa4abAQNr0H50G4Y14ogcggeazCKljtMXtZKIgFaoVWKVWnJh-xSPEW4Dzo3exyytVVZFh8sDHsonDl7TmhEH2n9d6K3m_ILYYHiWaH09ZZIb2-lp7G2BIfL2U-Ibahf12cA0nKskrc6UMpaCbPs95iEVTYOY0qgLz_95IEYTjF7PoStKwtDiFOBfCH8WQlfWb-rC6MFbAfNDDnfEOKhvDiDGgzxqtXb-U1_nK1aQ3Sfq4CACyZZ9aji7ufP86vo8H4KPamBzK4IKg5vwWLQPV62h2XccIfLAnSQYU8OGKPGa6O3WZ6Ji2MKItKM1n5C0YKMXRs-FDsvDwkzdVhKBn-yxMZEnn4OtFGTME-m4yA14vQcUDMhyJNM6ahAlF2Rnef5BRQeIpz6MTw1OBkKw_dNI37_jo_1f-_09-uil9Q_X95z-yC7kOD0U3OldaO7FWgP2OR78-PHRU4F-qIlFxBPJqhvdumbYIeS0rwkdmJZoeyjYDGy5TY3FK4MeVIrbGSUFRzm64A6tEwm24t503xgXu4t2dXTnneM_Bu-BvAUQEBVgKOiKzwsPpHiOA9RlPL5OFSckGcMAYeDRuEE1EWDdN2wSrEc6xRLc5FwrrE0iNMbOpQ9Lr6mL69GN6vJ8fbm_W7z_SdhWT66f2NNMcquDvxAdpfsuAVXt_UzrErOIejYgQeomt72qCROQ9M65BTm3_CHJYWSx4xuQpfjSgttvPi8yTvXK3rkzwgHZT5R-DU-VIabxWAYVVhM5Rw-IxBcy9N9lZSSd8e4NDRafSWtiACxu7Eu4F8LLSMTIN9BCDKamirdEx8vpZ_NPXgYAnu7OAcyWwIgsQVtRGYSYlxIgZpVKyeOMGmhaMay8NbGLeAjORzU3zS5YihHuE8BCYfnyS5fYMs4MsPbbG5x-6kcTyq9m8yBU25IG9UbSzgC5-CHtwsrogt6MZpguQ8uSU9tz4CkAlcRy0)](https://editor.plantuml.com/uml/hLRDJjj04BxxAKOvKASa4abAQNr0H50G4Y14ogcggeazCKljtMXtZKIgFaoVWKVWnJh-xSPEW4Dzo3exyytVVZFh8sDHsonDl7TmhEH2n9d6K3m_ILYYHiWaH09ZZIb2-lp7G2BIfL2U-Ibahf12cA0nKskrc6UMpaCbPs95iEVTYOY0qgLz_95IEYTjF7PoStKwtDiFOBfCH8WQlfWb-rC6MFbAfNDDnfEOKhvDiDGgzxqtXb-U1_nK1aQ3Sfq4CACyZZ9aji7ufP86vo8H4KPamBzK4IKg5vwWLQPV62h2XccIfLAnSQYU8OGKPGa6O3WZ6Ji2MKItKM1n5C0YKMXRs-FDsvDwkzdVhKBn-yxMZEnn4OtFGTME-m4yA14vQcUDMhyJNM6ahAlF2Rnef5BRQeIpz6MTw1OBkKw_dNI37_jo_1f-_09-uil9Q_X95z-yC7kOD0U3OldaO7FWgP2OR78-PHRU4F-qIlFxBPJqhvdumbYIeS0rwkdmJZoeyjYDGy5TY3FK4MeVIrbGSUFRzm64A6tEwm24t503xgXu4t2dXTnneM_Bu-BvAUQEBVgKOiKzwsPpHiOA9RlPL5OFSckGcMAYeDRuEE1EWDdN2wSrEc6xRLc5FwrrE0iNMbOpQ9Lr6mL69GN6vJ8fbm_W7z_SdhWT66f2NNMcquDvxAdpfsuAVXt_UzrErOIejYgQeomt72qCROQ9M65BTm3_CHJYWSx4xuQpfjSgttvPi8yTvXK3rkzwgHZT5R-DU-VIabxWAYVVhM5Rw-IxBcy9N9lZSSd8e4NDRafSWtiACxu7Eu4F8LLSMTIN9BCDKamirdEx8vpZ_NPXgYAnu7OAcyWwIgsQVtRGYSYlxIgZpVKyeOMGmhaMay8NbGLeAjORzU3zS5YihHuE8BCYfnyS5fYMs4MsPbbG5x-6kcTyq9m8yBU25IG9UbSzgC5-CHtwsrogt6MZpguQ8uSU9tz4CkAlcRy0)