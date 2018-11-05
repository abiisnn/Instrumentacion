var ConvertirGV = function(grados){
	var grados = parseFloat(document.getElementById("Grados").value);
	if((grados >= 20) && (grados <= 180))
	{
		var voltaje = -4.20146 + 0.576209*grados - 0.0303426*Math.pow(grados, 2) + 0.000803682*Math.pow(grados, 3) - 0.0000118802*Math.pow(grados, 4) + 1.03454*Math.pow(10, -7)*Math.pow(grados, 5) -5.28161*Math.pow(10, -10)*Math.pow(grados, 6) + 1.46335*Math.pow(10, -12)*Math.pow(grados, 7) -1.69911*Math.pow(10, -15)*Math.pow(grados, 8);
		console.log(voltaje);
		var inputVoltaje = document.getElementById("InputVoltaje");
  		inputVoltaje.value = voltaje.toFixed(4) + "V";
	}
	else
	{	
		var inputGrados = document.getElementById("Grados");
		inputGrados.value = "Invalido";
	}
}