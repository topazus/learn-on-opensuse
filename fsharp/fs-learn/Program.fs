open System.Runtime.Intrinsics.X86
// use System.Runtime.Intrinsics.X86.X86base.CpuId method to print the processor brand
// if it supports CPUID instruction
// let getProcessorBrand() =
//     if X86Base.IsSupported then
//         let (eax, ebx, ecx, edx) = X86Base.CpuId(0x80000002u, 0u)
//         let brand = sprintf "%08x%08x%08x%08x" eax ebx ecx edx
//         printfn "Processor brand: %s" brand
//     else
//         printfn "CPUID instruction is not supported"


