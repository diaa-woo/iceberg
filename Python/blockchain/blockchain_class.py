import datetime
import hashlib
import json

class Blockchain:
    def __init__(self):
        self.chain = []
        self.create_block(proof = 1, previous_hash = '0')   # 처음 블록(generis) 생성을 위한 proof
        
    def create_block(self, proof, previous_hash):
        block = {       # JSON으로 구조화된 block 생성
            'index': len(self.chain) + 1,
            'timestamp': str(datetime.datetime.now()),
            'proof': proof,
            'previous_hash': previous_hash
        }
        self.chain.append(block)
        return block
    
    def get_previous_block(self):   # 리스트에 있는 가장 마지막 블록 리턴
        return self.chain[-1]
    
    def proof_of_work(self, previous_proof):    # 이전 proof 값을 받고 previous_proof와의 연산 해시 값이 특정 조건을 만족하는 new_proof를 찾아 리턴
        new_proof = 1
        check_proof = False
        
        while check_proof is False:
            hash_operation = hashlib.sha256(str(new_proof**2 - previous_proof**2).encode()).hexdigest()
            if hash_operation.startswith('0000'):
                check_proof = True
            else:
                new_proof += 1
            
        return new_proof
    
    def hash(self, block):  # 딕셔너리 형태의 block을 받아서 json으로 dump하고 인코딩하여 해시값을 얻어 리턴
        encoded_block = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(encoded_block).hexdigest()
    
    
    