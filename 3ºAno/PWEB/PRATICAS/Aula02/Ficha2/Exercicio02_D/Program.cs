﻿using System;
using System.Linq;
using System.Collections.Generic;

// usando query syntax ou extension methods

namespace Exercicio02_D
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] ListaUm = {  "C#", "Aprender C#","ASP.NET Core com C#",
                "Entity Framework", "Bootstrap", "Identity", "Lambda", "Delegates",
                "Linq", "POO com C# "};
            string[] ListaDois = { "C#", "ASP.NET Core", "Linq", "Lambda e C#" };
            int[] Numeros = { 10, 23, 54, 77, 85, 12, 1, 4, 53 };

            // linq extension method
            var resultado = ListaUm.Select(e => e.Split(" ").Length);
            

            //foreach(var x in resultado)
            //    Console.WriteLine(x);

            // linq query method
            var resultado2 = from e in ListaUm select e.Split(" ").Length;

            foreach (var x in resultado)
                Console.WriteLine(x);



        }
    }
}
