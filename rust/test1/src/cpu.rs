use crate::utils::read_file_as_string;
// read files in `/sys/devices/system/cpu/cpu0/cpufreq` directory to retrieve cpu frequency

// `/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq` file
fn max_freq() -> u32 {
    let path = "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq";
    let contents = read_file_as_string(path);
    let max_freq = contents.trim().parse::<u32>().unwrap();
    max_freq
}
