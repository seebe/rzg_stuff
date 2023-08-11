# Device Tree Parsing Tool

**Purpose**
* This tool is to show all the included files for a single .dts file. This is helpful when there are many include files that include other include files and it gets difficult to follow.
* For each included file, it will also show you which perphal nodes are set in that file. For example, you want to find all the the .dtsi files that configure the i2c channels because you are looking for examples.

**Usage**
* You pass the file name of a Device Tree .dts file, and then it will list all the #include files so you can know all the files that are include, and in what order.
* Also, for each file, it will print out what new nodes were created, as well as nodes that are being modifed/added. When a node begins with &, it means it is overriding/modifying a previously declared node. In some complext Device Trees, a node my be mofided multiple times, so you have to know the order in which it was modifed to know the final values.

**Example usage on the Device Tree of the RZ/G2L SMARC**
* For this example, we will just downlaod the single python script file (not this entire repositry).
<pre>
$ cd rz_linux-cip/arch/arm64/boot/dts/renesas

$ wget https://raw.githubusercontent.com/seebe/rzg_stuff/master/dts_parser/dts_parser.py

$ python3 dts_parser.py r9a07g054l2-smarc.dts

-----------------------------------
Include order
-----------------------------------
 
r9a07g054l2-smarc.dts
└─r9a07g054l2.dtsi
  └─r9a07g054.dtsi
└─rzg2l-smarc-som.dtsi
└─rzg2l-smarc-pinfunction.dtsi
└─rz-smarc-common.dtsi
└─rzg2l-smarc.dtsi
 
 
-------------------------------------------------------------
Order of how files and nodes are parsed.
-------------------------------------------------------------
Remember, the #include is at the top of the files and the nodes come after. So that means the last file
that gets included will have the nodes that get processed first. This is important to know when you have
multiple files that modify the same node.
 
r9a07g054.dtsi
  nodes new: 
	audio_clk1		audio_clk2		can_clk			extal_clk		
	firmware		cluster0_opp		cpus			psci			
	gpu_opp_table		soc			thermal-zones		timer			 
  nodes override: 
	 
 
r9a07g054l2.dtsi
  nodes new: 
	 
  nodes override: 
	 
 
rzg2l-smarc-som.dtsi
  nodes new: 
	aliases			chosen			memory@48000000		reserved-memory		
	mmngr			mmngrbuf		vspm_if			reg_1p8v		
	reg_3p3v		reg_1p1v		vccq_sdhi0		phy0			
	phy1			adc_pins		eth0_pins		eth1_pins		
	gpio-sd0-pwr-en-hog	qspi0_pins		sd0-dev-sel-hog		sdhi0_emmc_pins		
	sdhi0_pins		sdhi0_pins_uhs		flash@0			pmic			
	rtc			 
  nodes override: 
	&adc			&eth0			&eth1			&extal_clk		
	&gpu			&ostm1			&ostm2			&pinctrl			
	&sbc			&sdhi0			&sdhi0			&wdt0			
	&wdt1			&wdt2			&poega			&poegb			
	&poegc			&poegd			&gpt4			&ehci0			
	&ohci0			&ehci1			&ohci1			&i2c3			 
 
rzg2l-smarc-pinfunction.dtsi
  nodes new: 
	can0_pins		can0-stb-hog		can1_pins		can1-stb-hog		
	i2c0_pins		i2c1_pins		i2c3_pins		mtu3_pins		
	scif0_pins		scif2_pins		sd1-pwr-en-hog		sdhi1_pins		
	sdhi1_pins_uhs		sound_clk_pins		spi1_pins		ssi0_pins		
	ssi1_pins		usb0_pins		usb1_pins		gpt4_pins		 
  nodes override: 
	&pinctrl			 
 
rz-smarc-common.dtsi
  nodes new: 
	aliases			chosen			snd_rzg2l		usb0_vbus_otg		
	vccq_sdhi1		hdmi-out		clk_ext_camera		ov5645_vdddo_1v8	
	ov5645_vdda_2v8		ov5645_vddd_1v5		channel0		channel1		
	ov5645			adv7535			ports			ports			 
  nodes override: 
	&audio_clk1		&audio_clk2		&canfd			&ehci0			
	&ehci1			&hsusb			&i2c0			&i2c1			
	&ohci0			&ohci1			&phyrst			&scif0			
	&sdhi1			&spi1			&usb2_phy0		&usb2_phy1		
	&du			&dsi0			&cru			&csi2			
	&mtu3			 
 
rzg2l-smarc.dtsi
  nodes new: 
	aliases			sound_card		x1_clk			versa3			
	wm8978			ports			mtu3_ch34		 
  nodes override: 
	&cpu_dai			&codec_dai		&i2c3			&scif2			
	&ssi0			&ssi1			&vccq_sdhi1		&ov5645			
	&adv7535			&mtu3			&poe3			 
 
r9a07g054l2-smarc.dts
  nodes new: 
	reserved-memory		 
  nodes override: 

</pre>

**Example of parsing every .dts in the directory and saving it as a txt file**
<pre>
$ mkdir parser_output
$ for file in $(ls *.dts) ; do  echo "$file" ;  python3 dts_parser.py $file > parser_output/${file}.txt ; done
</pre>
