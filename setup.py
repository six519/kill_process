#!/usr/bin/env python
import subprocess
from distutils.core import setup
from distutils.extension import Extension
from distutils.command.build import build as _build


class build(_build):
    def run(self):
        subprocess.call([
            'nasm',
            '-f',
            'elf64',
            'kill_process.asm'
        ])
        _build.run(self)

setup(name="kill_process",
    version="1.0",
    description="Extending Python with Assembly Language and C Sample Code",
    author="Ferdinand Silva",
    author_email="ferdinandsilva@ferdinandsilva.com",
    url="https://github.com/six519/kill_process",
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Natural Language :: English',
        'Programming Language :: Python',
		'Programming Language :: C',
        'Topic :: Software Development :: Libraries :: Python Modules',
    ],
    download_url="https://github.com/six519/kill_process",
    ext_modules=[
        Extension("kill_process",  
            sources = ["kill.c"],
            extra_objects= ["kill_process.o"]
        )
    ],
    cmdclass={
        'build': build
    },
    data_files=[
        ('', ['kill_process.asm'])
    ]
)