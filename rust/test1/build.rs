extern crate bindgen;
fn main() {
    // println!("cargo:rustc-link-search=/usr/include/zypp");
    // Tell cargo to tell rustc to link the library
    // compiler -l flag
    println!("cargo:rustc-link-lib=rpm");
    // println!("cargo:rustc-link-lib=static=fmt");
    // println!("cargo:rustc-link-lib=static=calc_rpms");
    // Tell Cargo that if the given file changes, to rerun this build script.
    println!("cargo:rerun-if-changed=src/calc_rpms.cpp");
    cc::Build::new()
        .cpp(true)
        .file("src/calc_rpms.cpp")
        // .cpp_link_stdlib("stdc++")
        .compile("calc_rpms");
}
