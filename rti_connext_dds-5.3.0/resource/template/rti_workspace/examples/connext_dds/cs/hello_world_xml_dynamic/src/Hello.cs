/* ****************************************************************************
 *         (c) Copyright, Real-Time Innovations, All rights reserved.       
 *                                                                          
 *         Permission to modify and use for internal purposes granted.      
 * This software is provided "as is", without warranty, express or implied. 
 *                                                                          
 * ****************************************************************************
 */
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Hello
{
    public class Hello
    {
        public static void Main(string[] argv)
        {
            int sampleCount = 0; // infinite loop
            bool runPub = true;
            if (argv.Length >= 1)
            {
                if (argv[0].Equals("sub"))
                {
                    runPub = false;
                }
                else if (argv[0].Equals("pub"))
                {
                }
                else
                {
                    Console.Error.WriteLine("Parameter 1 must be 'pub' or 'sub'");
                }
            } else
            {
                Console.Error.WriteLine("Parameter 1 must be 'pub' or 'sub'");
            }
            if (argv.Length >= 2)
            {
                sampleCount = Int32.Parse(argv[1]);
            }

            if (runPub == true)
            {
                HelloPublisher publisher = new HelloPublisher(sampleCount);
                publisher.Dispose();
            }
            else
            {
                HelloSubscriber subscriber = new HelloSubscriber(sampleCount);
                subscriber.Dispose();
            }
        }
    }
}
