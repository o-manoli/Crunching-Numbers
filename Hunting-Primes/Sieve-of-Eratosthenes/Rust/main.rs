

fn sieve(up2:u32) -> Vec<u32>{

	let mut v:Vec<u32> = (1..(up2+1)).step_by(2).collect();
	v[0] =2;
	let mut p: u32 = 3;
	let mut pp: u32;
	let mut i: u32 = 1;

	while ({pp = p*p; pp} < up2){
		pp = pp>>1;

		for e in v[pp as usize..].iter_mut().step_by(p as usize){
			*e = 0;
		}

		while v[{i+=1;i as usize}] == 0 {};

		p = v[i as usize];
	}

	v.retain(|&x| x != 0);

	v
}


fn main() {
	let primes = sieve(7919);
	// println!("{:?}", primes);
	println!("{}", primes.len());
}

