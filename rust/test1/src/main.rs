use test1::{
    calc_rpms::{get_rpm_packages_count_by_librpm, rpm_packages_name},
    time_utils::current_time,
};

// std::os::raw::c_char to str
fn char_arr_to_str(arr: *mut i8) -> &'static str {
    let mut i = 0;
    unsafe {
        while *arr.offset(i) != 0 {
            i += 1;
        }
        let slice = std::slice::from_raw_parts(arr as *const u8, i as usize);
        std::str::from_utf8(slice).unwrap()
    }
}

fn char_arr_to_str2(arr: &[u8]) -> &str {
    let mut i = 0;
    for c in arr {
        if *c == 0 {
            break;
        }
        i += 1;
    }
    let slice = &arr[0..i];
    std::str::from_utf8(slice).unwrap()
}
fn main() {}
fn t1() {
    let a = unsafe { current_time() };
    let b = char_arr_to_str(a);
    println!("{}", b);
}
